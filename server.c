// Basit HTTP sunucusu: GET /static ve /api/hello destekler
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <fcntl.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void serve_static(int client_fd, const char *path);
void send_hello_api(int client_fd);
void send_404(int client_fd);

void handle_client(int client_fd) {
    char buffer[BUFFER_SIZE];
    int bytes = read(client_fd, buffer, BUFFER_SIZE - 1);
    if (bytes <= 0) return;

    buffer[bytes] = '\0';

    char method[8], path[1024];
    sscanf(buffer, "%s %s", method, path);

    if (strcmp(method, "GET") != 0) {
        send_404(client_fd);
        return;
    }

    if (strcmp(path, "/api/hello") == 0) {
        send_hello_api(client_fd);
    } else if (strncmp(path, "/static/", 8) == 0) {
        serve_static(client_fd, path + 8);
    } else {
        send_404(client_fd);
    }
}

void serve_static(int client_fd, const char *filename) {
    char filepath[1024];
    snprintf(filepath, sizeof(filepath), "static/%s", filename);
    FILE *file = fopen(filepath, "r");
    if (!file) {
        send_404(client_fd);
        return;
    }

    char ext[16], *dot = strrchr(filename, '.');
    if (dot) strcpy(ext, dot + 1);
    else strcpy(ext, "txt");

    char content_type[64] = "text/plain";
    if (strcmp(ext, "html") == 0) strcpy(content_type, "text/html");
    else if (strcmp(ext, "css") == 0) strcpy(content_type, "text/css");
    else if (strcmp(ext, "js") == 0) strcpy(content_type, "application/javascript");

    dprintf(client_fd, "HTTP/1.1 200 OK\r\nContent-Type: %s\r\n\r\n", content_type);

    char ch;
    while ((ch = fgetc(file)) != EOF) write(client_fd, &ch, 1);
    fclose(file);
}

void send_hello_api(int client_fd) {
    const char *response = "{\"message\": \"Hello, world!\"}";
    dprintf(client_fd, "HTTP/1.1 200 OK\r\nContent-Type: application/json\r\n\r\n%s", response);
}

void send_404(int client_fd) {
    const char *response = "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\n\r\n404 - Not Found";
    write(client_fd, response, strlen(response));
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 10);
    printf("Server running on port %d\n", PORT);

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr*)&addr, &addrlen);
        if (client_fd >= 0) {
            handle_client(client_fd);
            close(client_fd);
        }
    }

    return 0;
}

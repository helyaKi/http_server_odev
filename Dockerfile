FROM gcc:latest

WORKDIR /app

COPY . .

RUN gcc -o server server.c

EXPOSE 8080

CMD ["./server"]

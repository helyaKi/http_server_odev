# HTTP Server Ödevi

Bu proje, C dili kullanılarak sıfırdan geliştirilmiş bir HTTP sunucusudur. Framework kullanılmadan socket programlama ile geliştirilmiştir.

## Özellikler

✅ Temel HTTP Sunucu İşlevi:
C diliyle düşük seviyeli socket programlama kullanılarak yazılmıştır. HTTP/1.1 protokolü üzerinden gelen istemci isteklerini kabul eder ve yanıt verir.

📁 Statik Dosya Sunumu (Static File Serving):
static/ klasörü altındaki HTML, CSS, JS gibi dosyalar /static/<dosya_adı> yoluyla tarayıcıya sunulabilir. Örneğin:
http://localhost:8080/static/index.html isteği, static/index.html dosyasını yükler.

🧠 MIME Type Desteği:
Sunulan dosyalar, uzantısına göre uygun içerik türü (Content-Type) ile yanıtlanır. Örnek:
.html için text/html, .css için text/css, .js için application/javascript.

🌐 Basit API Endpoint:
/api/hello adresi, sabit bir JSON yanıtı döner:
{"message": "Hello, world!"}
Bu endpoint frontend uygulamaları için örnek REST API’dir.

❌ 404 Hatası Yönetimi:
Tanınmayan yollar veya eksik dosya isteklerinde kullanıcıya "404 - Not Found" mesajı döndürülür.

🐳 Docker Desteği (compose’suz):
Dockerfile kullanılarak sunucunun container ortamında çalışması sağlanır. Docker imajı derlenip 8080 portu üzerinden dış dünyaya açılır.

⚡ Framework Bağımsız:
Ek bir framework ya da kütüphane kullanılmamıştır. Tüm işlevler doğrudan POSIX sistem çağrıları ve C standart kütüphanesi ile gerçekleştirilmiştir.

## Kurulum

```bash
gcc -o server server.c
./server
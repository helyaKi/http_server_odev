# HTTP Server Ödevi

## 🧑‍🎓 Öğrenci Bilgileri:
        Helia Rezapour Kiani
        170422993

## 🔗 GitHub Repo Linki
        

## 📝 Açıklama

### Projenin Amacı ve Özeti

Bu projede, C programlama dili kullanılarak sıfırdan temel bir HTTP sunucusu geliştirilmiştir. Projenin amacı, düşük seviyeli ağ programlama konseptlerini uygulamalı olarak öğrenmek ve HTTP protokolünün temel çalışma prensiplerini kavramaktır. 

Sunucu, POSIX socket API'leri kullanılarak TCP üzerinden bağlantı kurar ve istemciden gelen HTTP GET isteklerine yanıt verir. Statik bir HTML sayfası döndürülerek istemciye temel bir web sayfası gösterilir. Desteklenmeyen yollar ya da hatalı istekler için sunucu 404 Not Found yanıtı üretir.

Sunucunun platform bağımsız olarak dağıtılabilmesi amacıyla Docker kullanılarak kapsüllenmiştir. Bu sayede, farklı işletim sistemlerine sahip kullanıcılar projenin çalışma ortamını doğrudan Docker üzerinden kolaylıkla oluşturabilir. Dockerfile içerisinde gerekli adımlar tanımlanarak, sunucunun otomatik olarak derlenmesi ve çalıştırılması sağlanmıştır.

Bu ödev, yalnızca socket programlama bilgilerini pekiştirmekle kalmayıp aynı zamanda konteyner teknolojileri (Docker) ile yazılımın taşınabilirliğini, dağıtılabilirliğini ve sürdürülebilirliğini artırma konusunda da önemli bir deneyim sunmaktadır.

### Gerçekleştirilen Özellikler

- 📡 **TCP soketleri ile HTTP bağlantısı kurulumu**
- 🌐 **İstemciden gelen HTTP GET isteğine karşılık statik HTML içerik sunumu**
- ❌ **Geçersiz yollar için 404 Not Found yanıtı**
- 🐳 **Docker desteği ile platformdan bağımsız çalışma**
- 🧼 **Yorumlanabilir, okunabilir ve modüler kod yapısı**
- 📁 **Proje dökümantasyonu ve açık kaynak standartlarına uygun dosyalar (README, LICENSE, CONTRIBUTING vb.)**

### 📄 Lisans

Proje, açık kaynak MIT lisansı ile lisanslanmıştır. Tüm telif ve lisans bilgileri `LICENSE` dosyasında belirtilmiştir. Bu lisans sayesinde, proje herkes tarafından özgürce kullanılabilir, değiştirilebilir ve dağıtılabilir.

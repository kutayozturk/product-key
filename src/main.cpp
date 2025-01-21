#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

// Rastgele bir karakter seçme fonksiyonu
char randomChar() {
    int r = rand() % 36;  // 26 harf + 10 rakam
    if (r < 26) {
        return 'A' + r;  // A-Z arasındaki harfler
    } else {
        return '0' + (r - 26);  // 0-9 arasındaki rakamlar
    }
}

// Ürün anahtarı üretme fonksiyonu
string generateProductKey(int segments, int segmentLength) {
    stringstream productKey;
    for (int i = 0; i < segments; i++) {
        for (int j = 0; j < segmentLength; j++) {
            productKey << randomChar();
        }
        if (i < segments - 1) {
            productKey << "-";  // Her segmentin arasında "-" karakteri eklenir
        }
    }
    return productKey.str();
}

int main() {
    // Rastgele sayı üreticisini başlatma
    srand(time(0));

    // Anahtar için parametreler
    int segments = 4; // Anahtarın kaç segmentten oluşacağı
    int segmentLength = 5; // Her segmentin uzunluğu

    // Ürün anahtarını oluştur
    string productKey = generateProductKey(segments, segmentLength);

    // Ürün anahtarını ekrana yazdır
    cout << "Ürün Anahtarı: " << productKey << endl;

    return 0;
}

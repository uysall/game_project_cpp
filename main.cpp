#include <iostream>
#include <unistd.h> //Yılanın hareketini ayarlamak için kullanıyoruz
#include <termios.h>//klavye tuşların anlık tepki vermek için karakteri daha iyi yönetebilmek için
#include <cstdlib>//yemlerin ekranda rastgele konumlanmasını sağlıyor
#include <cstring>//oyuncu ismini ve yapılan en yüksek skoru saklamak için kullanılıyor

int main() {
    constexpr int WIDTH = 20; //enlemesine alan oluşturmak için kullanıyoruz
    constexpr int HEIGHT = 10; //yükseliğini oluştumak için kullanıyoruz
    bool gameOver; //yılan eğer hata yaparsa oyunun bittiğini anlıyoruz
    int x, y, fruitX, fruitY, score; //x ve y yılanın konumu belli eder fruitX, fruitY yemin konumu,score elde edile
    int tailX[100], tailY[100]; //yılanın kuyruk kordinatlarını saklamak için kullanılıyor
    int nTail; //yılan yem yediğinde yeni kuyruk eklemir

    enum eDirection { STOP = 0, LEFT = 1, RIGHT = 2, UP = 3, DOWN = 4 }; //yılanın haraket yönünü belirlemek için

    eDirection dir;

    void Setup(); {
        //oyunun başlangıç ayarlarını yapıyor
        gameOver = false; //gameOver false'dır çünkü oyun hala devam ediyor demektir
        dir = STOP; //başlangıçta yılan duru hareket etmez
        x = WIDTH / 2; //başlangıçta yılanın konumunu belirler  WIDTH(genişlik)
        y = HEIGHT / 2; //başlangıçta yılanın konumunu belirler  HEIGHT(yükseklik)
        fruitX = rand() % WIDTH; //meyvenin yatay olarak rastgele konumu beelirler
        fruitY = rand() % HEIGHT; //meyvenin yükseklik olarak rastege konumu belirler
        score = 0; //oyun başlangıçta score 0'dır
        nTail = 0; //yılana eklenen kuyrukta aynı şekilde 0'dır
    }

    void Draw(); {
        //ekrandaki yılanı ve meyveyi çizen fonksiyon
        system("clear"); //ekranı temizler bu sayede çizimler üst üste gelmez
        for (int i = 0; i < WIDTH + 2; i++)
            std::cout << "#"; // üst sınırı # ile çizer
        std::cout << std::endl;

        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (j == 0)
                    std::cout << "#"; //sol sınırı  # ile çizer

                if (i == y && j == x)
                    std::cout << "O"; // Yılanın başını O ile çizer
                else if (i == fruitY && j == fruitX)
                    std::cout << "F"; //meyveyi  F ile çizer
                else {
                    bool print = false;
                    for (int k = 0; k < nTail; k++) {
                        if (tailX[k] == j && tailY[k] == i) {
                            std::cout << "o"; //yılanın kuyruğunu o
                            print = true;
                        }
                    }
                    if (!print)
                        std::cout << " "; //boş hücre ise boşluk karakteri ile doldurur
                }
            }
        }
    }
}

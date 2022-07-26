#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
int sayac1 = 0;
int sayac2 = 0;
void olustur();
void ekle(int, int);
void guncelle(int, int);
void sil(int);
void yazdir();
void bosalt();

struct Node {
    int deger;
    Node* sonraki;
};

struct LinkedList {
    Node* bas;
    void olustur();
    void ekle(int, int);
    void guncelle(int, int);
    void sil(int);
    void yazdir();
    void bosalt();
    int sayac;
};

struct ArrayList {
    int* bas;
    void olustur();
    void ekle(int, int);
    void guncelle(int, int);
    void sil(int);
    void yazdir();
    void bosalt();
    double sayac;
};

const int iteration = 30000;
int main()
{
    ArrayList* al = new ArrayList();
    
    for (int i = 0;i < iteration;i++) {
        al->ekle(i, i);
    }

    
    auto begin2 = std::chrono::high_resolution_clock::now();


    al->ekle(20, 1);
    

    auto end2 = std::chrono::high_resolution_clock::now();
    cout << endl;

    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
    cout << iteration << " elemanli bir dizide:  ";
    cout << "Ekleme Suresi => " << elapsed2.count() << " nano - saniye" << endl;

    LinkedList* l = new LinkedList();

    l->olustur();

    for (int i = 0;i < iteration;i++)
        l->ekle(i, i);


    auto begin1 = std::chrono::high_resolution_clock::now();

    l->ekle(92, 1);
    auto end1 = std::chrono::high_resolution_clock::now();
    cout << endl;

    auto elapsed1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
    cout << iteration << " elemanli bir listede:  ";
    cout << "Ekleme Suresi=> " << elapsed1.count() << " nano - saniye" << endl;
    
    cout << endl;
   

    return 0;
}

void LinkedList::olustur() {
    bas = NULL;
}

void LinkedList::ekle(int a, int b) {

    Node* n = new Node();
    n->deger = a;

    if (bas == NULL) {
        bas = n;
        return;
    }
    Node* tara;
    tara = bas;
    while (tara) {
        sayac++;
        tara = tara->sonraki;
    }
    tara = bas;
    for (int i = 0;i < b - 1;i++) {
        tara = tara->sonraki;
    }
    n->sonraki = tara->sonraki;
    tara->sonraki = n;
}

void LinkedList::guncelle(int sirano, int yenieleman) {
    Node* yeni = new Node();
    yeni->deger = yenieleman;
    Node* tara;
    int sayac__ = 1;
    tara = bas;
    while (tara && (sayac__ < sirano)) {
        sayac__++;
        tara = tara->sonraki;
    }
    if (tara != NULL) {
        yeni->sonraki = tara->sonraki;
        *tara = *yeni;
    }
    else {
        cout << "Guncellenecek kayit numarasi hatali.\n";
    }
}

void LinkedList::sil(int sirano) {
    Node* tara, * arka;
    int sayac_ = 1;
    arka = tara = bas;
    if (sirano <= 0) {
        cout << "Hatali kayit sira numarasi.\n";
        return;
    }
    if (sirano == 1) {
        bas = bas->sonraki;
        delete tara;
        sayac--;
        return;
    }
    while ((tara != NULL) && (sayac_ < sirano)) {
        arka = tara;
        tara = tara->sonraki;
        sayac_++;
    }
    if (sayac < sirano) {
        cout << "Silenecek kayit bulunamadi.\n";
    }
    else {
        arka->sonraki = tara->sonraki;
        delete tara;
        sayac--;
    }
}

void LinkedList::yazdir() {
    Node* tara;
    tara = bas;
    if (!tara) {
        cout << "Liste Bos!" << endl;
        return;
    }
    while (tara) {
        cout << tara->deger << " ";
        tara = tara->sonraki;
    }
    cout << endl;
}

void LinkedList::bosalt() {
    Node* p;
    while (bas) {
        p = bas;
        bas = bas->sonraki;
        delete p;
    }
    sayac = 0;
}
void ArrayList::olustur() {
    bas = NULL;
    sayac = 0;
}
int arr[iteration];
void ArrayList::ekle(int a, int b) {
    

    if(sayac == 0){
        bas = new int[1];
        bas[b] = a;
    }
    else {
        int* gecici = bas;
        bas = new int[sayac+1];
        for (int i = 0; i < b; i++)
            bas[i] = gecici[i];
        bas[b] = a;
        for (int i = b+1; i < sayac + 1; i++)
            bas[i] = gecici[i];
    }
    
    sayac++;
}
void ArrayList::guncelle(int sirano, int yenieleman) {
    for (int i = 0;i < sirano;i++) {
        arr[sirano - 1] = yenieleman;
        //*(bas + sirano - 1) = yenieleman;
    }
}

void ArrayList::sil(int sirano) {

    int* tara = bas;
    for (int i = sirano;i < iteration;i++) {
        *(tara + i - 1) = *(tara + i);
        sayac1++;
    }
}

void ArrayList::bosalt() {
    int* tara = bas;
    for (int i = sayac;i > 0;i--) {
        *(tara + i - 1) = *(tara + i);
        //sayac2=30;
    }

}
void ArrayList::yazdir() {
    for (int i = 0;i < sayac;i++) {
        cout << *(bas+i) << " ";
    }
    
    cout << endl;
}


#include <iostream>
using namespace std;
#define MAX 8

struct Antrian{
    int data[MAX];
    int head;
    int tail;
};

Antrian antre;
void create();
bool isEmpty();
bool isFull();
void enqueue(int);
int dequeue();
void tampil();

int main()
{
    int pilih, data;

    pil_menu:
    cout << "Pilih program" << endl;
    cout << "=============" << endl;
    cout << "1. Tambah data" << endl;
    cout << "2. Hapus data" << endl;
    cout << "3. Tampil data" << endl;
    cout << endl;
    cout << "Masukkan Pilihan : ";
    cin >> pilih;

    switch(pilih){
        case 1 : cout << "\nMasukkan data : ";
                 cin >> data;
                 enqueue(data);
                 goto pil_menu;break;

        case 2 : cout << "\nHapus data\n" << endl;
                 dequeue();
                 goto pil_menu;break;

        case 3 : cout << "\nData antrian : ";
                 tampil();
                 goto pil_menu;break;

        default :cout<<"Tidak Tersedia!!!";break;
    }
    return 0;
}

void create(){
    antre.head = antre.tail = -1;
}

//cek apakah antrian kosong
bool isEmpty(){
    if(antre.tail == -1){
        return true;
    }
    else{
        return false;
    }
}

//cek apakah antrian penuh
bool isFull(){
    if(antre.tail == MAX ){
            return true;
    }
    else{
        return false;
    }
}

//menambah data ke antrian
void enqueue(int data){
    if(isFull()){
        cout << "Antrian penuh" << endl;
    }
    else{
        antre.data[antre.tail] = data;
        antre.tail++;
        cout << data << " masuk dalam antrian" << endl;
    }
    cout << endl;
}

//mengambil data antrian
int dequeue(){
    if(isEmpty()){
        cout<<"Antrian kosong";
    }
    else{
        int e = antre.data[antre.head];
        //menggeser antrian data ke head
        for(int i=0;i<antre.tail;i++){
            antre.data[i] = antre.data[i+1];
        }
        antre.tail--;
        return e;
    }


}

//menampilkan antrian
void tampil(){
    if(isEmpty()){
        cout << "Antrian kosong";
    }
    else{
        for(int i = 0;i<MAX;i++){
            if(antre.data[i] == NULL){
                cout << "Data Kosong ";
            }
            else{
                cout << antre.data[i] << " ";
            }
        }
    }
    cout << endl << endl;
}

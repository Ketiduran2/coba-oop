#include <iostream>

using namespace std;

class mhs{
    public:
        string nim;
        string nama;
        int nil;
};

class dt{
    public:
        string email;
        string pw;
};

dt reg(dt arr[], int size){
    string email,pw,pwc;
    int r;

    while (true){
        cout << "Masukan Email: ";
        cin >> email;

        for (int i = 0; i < size; i++){
            if (email != arr[i].email){
                r = 0;
            }
            else {
                r = 1;
                break;
            }   
        }
        if(r == 1){
            cout << "Email sudah di pakai " << endl;
        }
        else{
            break;
        }
    }
    while(true){
        cout << "Masukan Password: ";
        cin >> pw;
        cout <<"Konfirmasi Password: ";
        cin >> pwc;

        if(pw != pwc){
            cout << "Password tidak sama" << endl;
        }
        else{
            break;
        }    
    }   
    arr[size].email = email;
    arr[size].pw = pw;
    return arr[size];
}

bool login(dt arr[], int size){
    string email, pw, pil;
    int r,n;
    

    while (true)
    {
        cout << "Masukan email : ";
        cin >> email;
        cout << "Masukan Password: ";
        cin >> pw;

        for (int i = 0; i < size; i++){
            if (email == arr[i].email && pw == arr[i].pw ){
                r = 1;
                break;
            }
            else{
                r = 0;
            }
        }

        if (r == 1){
            break;
        }
        else{
            cout << "Email / Password Salah!" << endl;
            cout << "Apakah anda ingin mengulang [Y/N]: ";
            cin >> pil;
            if (pil == "Y" || pil == "y"){
                n = 0;
            }
            else{
                n=1;
            }
        }
        if (n==1){
            break;
        }
    }
    if(n == 1){
        return false;
    }
    else{
        return true;
    }   
}

mhs tmbh(mhs arr[],int size){
    string nim, nama;
    int r;
    while(true){
        cout << "Masukan NIM: ";
        cin >> nim;

        for(int i = 0; i < size; i++){
            if(nim == arr[i].nim){
                r = 1;      
                break;
            }
            else{
                r=0;
            }
        }

        if (r == 0){
            cout << "Masukan Nama Mahasiswa : ";
            cin >> nama;
            arr[size].nama = nama;
            arr[size].nim = nim;
            arr[size].nil = NULL;
            break;
        }
        else{
            cout << "NIM sudah ada" << endl;
        }
    }
    return arr[size];
}

mhs nilai(mhs arr[], int size){
    string nim;
    int r,nil,in,n;

    while (true){
        cout << "Masukan NIM: ";
        cin >> nim;
        cout << "Masukan Nilai: ";
        cin >> nil;
        for (int i = 0; i < size; i++){
            if(nim == arr[i].nim){
                r = 1;
                in = i;
                break;
            }
            else{
                r=0;
            }
        }
        if(r == 1){
            if(arr[in].nil == NULL){
                arr[in].nil = nil;
                break;
            }
            else {
                cout << "Nilai sudah ada"<< endl;
                break;
            }
        }
        else{
            cout << "NIM tidak ada"<< endl ;
        }
        
    }
    return arr[in];
    
}

int main(){
    mhs mh[20];
    mh[0].nim = "001";
    mh[0].nil = 90;
    mh[0].nama = "Budi";
    mh[1].nim = "002";
    mh[1].nil = 70;
    mh[1].nama = "Joko";
    dt akun[20];
    akun[0].email = "testing1@gmail.com";
    akun[1].email = "testing2@gmail.com";
    akun[0].pw = "testing123";
    akun[1].pw = "testing234";
    int size2 = 2;
    int size =  2;
    bool n;
    string pil;
    int pil2;

    while(true){
        cout << "Aplikasi Mahasiswa" << endl << endl;
        cout << "Register / Login:";
        cin >> pil;

        if(pil != "Register" && pil != "Login" && pil != "login" && pil != "register"){
            if(pil == "Exit" || pil == "exit"){
                exit(0);
            }
            else{
                cout << "Invalid";
            }
        }
        else{
            if(pil == "Register" || pil == "register"){
                akun[size] = reg(akun, size);
                size += 1;
            }
            else{
                n = login(akun, size);
                if (n == true){
                    cout << "Akses diberikan" << endl << endl;

                    while(true){
                        cout << "Menu Aplikasi" << endl;
                        cout << "1. Lihat Mahasiswa" << endl;
                        cout << "2. Tambah Mahasiswa" << endl;
                        cout << "3. Input nilai" << endl;
                        cout << "4. Exit" << endl;
                        cout << "Pilih salah satu dari menu diatas: ";
                        cin >> pil2;
    
                        if(pil2 == 1 || pil2 == 2 || pil2 == 3 || pil2 ==4){
                            if (pil2 == 1){
                                for(int i = 0; i < size2; i++){
                                    cout << i + 1 << ". Nama: " <<  mh[i].nama << endl;
                                    cout << "   NIM : " << mh[i].nim << endl;
                                    cout << "   Nilai: " << mh[i].nil << endl << endl;
                                }

                            }
                            else if (pil2 == 2){
                                mh[size2] = tmbh(mh,size2);       
                                size2 += 1;
                            }
                            else if(pil2 == 3){
                                nilai(mh,size2);
                            }
                            else if(pil2 == 4 ){
                                exit(0);

                            }
                        }
                        else{
                            cout << "Invalid" << endl;
                        }
                    }
                }
                else{
                    cout << "Akses tidak diberikan" << endl;
                }
            }
        }
    }

    


}
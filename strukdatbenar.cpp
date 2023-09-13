#include <iostream>
#include <string>

using namespace std;

const int MAX_DATA = 10;


struct Data {
    string nama;
    int umur;
    string alamat;
};

//Menampilkan data
void tampilkanData(const Data data[], int jumlahData) {
    cout << "Data saat ini:" << endl;
    for (int i = 0; i < jumlahData; ++i) {
        cout << "Data ke-" << i+1 << ":" << endl;
        cout << "Nama: " << data[i].nama << endl;
        cout << "Umur: " << data[i].umur << endl;
        cout << "Alamat: " << data[i].alamat << endl << endl;
    }
}

//Menambahkan data
void tambahkanData(Data data[], int &jumlahData) {
    if (jumlahData < MAX_DATA) {
        cout << "Masukkan data baru:" << endl;
        cout << "Nama: ";
        cin >> data[jumlahData].nama;
        cout << "Umur: ";
        cin >> data[jumlahData].umur;
        cout << "Alamat: ";
        cin.ignore();
        getline(cin, data[jumlahData].alamat);
        jumlahData++;
        cout << "Data berhasil ditambahkan." << endl;
    } else {
        cout << "Kapasitas data sudah penuh." << endl;
    }
}

//Menghapus data
void hapusData(Data data[], int &jumlahData, const string &nama) {
    bool dataDitemukan = false;
    for (int i = 0; i < jumlahData; ++i) {
        if (data[i].nama == nama) {
            dataDitemukan = true;
            for (int j = i; j < jumlahData - 1; ++j) {
                data[j] = data[j + 1];
            }
            jumlahData--;
            cout << "Data berhasil dihapus." << endl;
            break;
        }
    }
    if (!dataDitemukan) {
        cout << "Data tidak ditemukan." << endl;
    }
}

//Mengubah Data
void ubahData(Data data[], int jumlahData, const string &nama) {
    for (int i = 0; i < jumlahData; ++i) {
        if (data[i].nama == nama) {
            cout << "Masukkan data yang baru:" << endl;
            cout << "Nama: ";
            cin >> data[i].nama;
            cout << "Umur: ";
            cin >> data[i].umur;
            cout << "Alamat: ";
            cin.ignore();
            getline(cin, data[i].alamat);
            cout << "Data berhasil diubah." << endl;
            return;
        }
    }
    cout << "Data tidak ditemukan." << endl;
}

//Mencari data
void cariData(const Data data[], int jumlahData, const string &nama) {
    cout << "Hasil pencarian untuk nama '" << nama << "':" << endl;
    for (int i = 0; i < jumlahData; ++i) {
        if (data[i].nama == nama) {
            cout << "Data ke-" << i + 1 << ":" << endl;
            cout << "Nama: " << data[i].nama << endl;
            cout << "Umur: " << data[i].umur << endl;
            cout << "Alamat: " << data[i].alamat << endl;
        }
    }
}

int main() {
    Data data[MAX_DATA];
    int jumlahData = 0;
    int pilihan;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambahkan Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Ubah Data" << endl;
        cout << "5. Cari Data" << endl;
        cout << "6. Keluar" << endl;
        cout << "Input: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanData(data, jumlahData);
                break;
            case 2:
                tambahkanData(data, jumlahData);
                break;
            case 3:
                {
                    string nama;
                    cout << "Masukkan nama yang ingin dihapus: ";
                    cin >> nama;
                    hapusData(data, jumlahData, nama);
                }
                break;
            case 4:
                {
                    string nama;
                    cout << "Masukkan nama yang ingin diubah: ";
                    cin >> nama;
                    ubahData(data, jumlahData, nama);
                }
                break;
            case 5:
                {
                    string nama;
                    cout << "Masukkan nama yang ingin dicari: ";
                    cin >> nama;
                    cariData(data, jumlahData, nama);
                }
                break;
            case 6:
                cout << "Terima kasih" << endl;
                break;
            default:
                cout << "Pilihan salah" << endl;
        }
    } while (pilihan != 6);

    return 0;
}

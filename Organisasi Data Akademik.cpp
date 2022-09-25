#include <iostream>

using namespace std;
int main()
{
    //Data
    string nama[50];
    int niu[50];
    float nilai[50];

    //Variabel untuk entri data
    short banyakData = 0;

    //Variabel untuk menu edit data
    bool editRunning;
    int nomorUrut;
    short indexEdit;

    //Variabel untuk menu cari data
    short indexCari, hasilCari;
    unsigned int cariNIU;
    string cariNama;

    //Variabel untuk menu urutkan data    
    short indexSort;
    string tempNama;
    int tempNIU;
    float tempNilai;
    bool urut, ascending;

    //Variabel untuk menu hapus data
    bool hapusRunning;

    cout << "----- Entri Data -----\n\n";
    cout << "Format Input: Nama_Tanpa_Spasi NIU Nilai\n";
    cout << "Contoh: Farhan_Arief_Ramadhan 123456 3.9\n\n";

    cout << "Jika ingin selesai mengisi sebelum 50 entri, masukkan -1 pada kolom nilai\n";
    cout << "Contoh: f -1 -1\n\n";

    cout << "Maksimal 50 Entri\n\n";
    for (int i = 0; i < 50; i++) {
        cout << "Input Data Mahasiswa Ke-" << i + 1 << endl;
        cout << "-> ";
        cin >> nama[i] >> niu[i] >> nilai[i];
        cout << endl;
        if (nilai[i] == -1)
            break;
        else
            banyakData++;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "Entri data selesai\n\n" << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";


    //Menu Utama
    int indexMenu = 0;
    bool running = true;

    while (running) {
        cout << "----- Laman Menu -----\n\n";
        cout << "Pilih menu lalu input index-nya\n";
        cout << "1 - Entri Data\n" << "2 - Edit Data\n" << "3 - Tampilkan Data\n" << "4 - Cari Data\n" << "5 - Urutkan Data\n" << "6 - Hapus Data\n" << "7 - Selesai\n";
        cout << "\nIndeks: ";
        cin >> indexMenu;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

        switch (indexMenu) {
        case 1 :
            //Entri Data
            cout << "----- Entri Data -----\n\n";
            cout << "Format Input: Nama_Tanpa_Spasi NIU Nilai\n";
            cout << "Contoh: Farhan_Arief_Ramadhan 123456 3.9\n\n";

            cout << "Jika ingin selesai mengisi sebelum 50 entri, masukkan -1 pada kolom nilai\n";
            cout << "Contoh: f -1 -1\n\n";

            cout << "Maksimal 50 Entri\n\n";
            
            for (int i = banyakData; i < 50; i++) {
                cout << "Input Data Mahasiswa Ke-" << i + 1 << endl;
                cout << "-> ";
                cin >> nama[i] >> niu[i] >> nilai[i];
                cout << endl;
                if (nilai[i] == -1)
                    break;
                else
                    banyakData++;
            }

            cout << "Entri data selesai\n\n" << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
            break;


        case 2 :
            //Edit Data
            editRunning = true;

            cout << "----- Edit Data -----\n\n";
            
            cout << "Masukkan nomor urut mahasiswa untuk mengubah datanya\n";
            cout << "Nomor urut berdasarkan urutan data\n";
            cout << "Nomor urut berbeda dengan NIU\n\n";

            cout << "Nomor Urut: ";
            cin >> nomorUrut;
            while (nomorUrut > banyakData) {
                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout << "Data mahasiswa bernomor urut " << nomorUrut << " belum dientri\n";
                cout << "Masukkan nomor urut yang valid!\n\n";
                cout << "Nomor Urut: ";
                cin >> nomorUrut;
            }
            nomorUrut--;            

            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

            //Menu Edit
            while (editRunning)
            {
                cout << "----- Menu Edit -----\n\n";

                cout << nama[nomorUrut] << " " << niu[nomorUrut] << " " << nilai[nomorUrut] << "\n\n";
                cout << "Data apa yang ingin diedit?\n";
                cout << "1 - Nama\n" << "2 - NIU\n" << "3 - Nilai\n" << "4 - Selesai Edit Data\n";
                cout << "\nIndeks: ";
                cin >> indexEdit;
                
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

                switch (indexEdit) {

                case 1 :
                    cout << "----- Edit Nama -----\n\n";

                    cout << "Ubah nama " << nama[nomorUrut] << "\nmenjadi: ";
                    cin >> nama[nomorUrut];
                    cout << "\nNama berhasil diubah menjadi " << nama[nomorUrut] << endl;

                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

                    break;

                case 2 :
                    cout << "----- Edit NIU -----\n\n";

                    cout << "Ubah NIU " << niu[nomorUrut] << "\nmenjadi: ";
                    cin >> niu[nomorUrut];
                    cout << "\nNIU berhasil diubah menjadi " << niu[nomorUrut] << endl;

                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

                    break;

                case 3 :
                    cout << "----- Edit Nilai -----\n\n";

                    cout << "Ubah nilai " << nilai[nomorUrut] << "\nmenjadi: ";
                    cin >> nilai[nomorUrut];
                    cout << "\nNilai berhasil diubah menjadi " << nilai[nomorUrut] << endl;

                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

                    break;

                case 4 :
                    editRunning = false;

                    break;

                default :
                    cout << "!!! Index menu tidak valid !!!\n\n";
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                }
            }
            cout << "----- Edit Data Selesai -----\n\n";

            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

            break;


        case 3 :
            //Tampilkan semua data
            cout << "----- Tampilkan Semua Data -----\n\n";

            cout << "Nama NIU Nilai\n\n";

            if (banyakData == 0) {
                cout << "--Tidak ada data tersedia--\n";
            }

            //Iterasi setiap anggota array untuk ditampilkan
            for (int i = 0; i < banyakData; i++) {
                cout << i + 1 << ") " << nama[i] << " " << niu[i] << " " << nilai[i] << endl;
            }            

            cout << "\nSemua data telah ditampilkan\n";
            cout << "Masukkan 0 untuk kembali ke menu utama\n";
            cout << "-> ";
            cin >> indexMenu;
            cout << endl;

            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";            

            break;


        case 4 :
            //Cari Data
            cout << "----- Cari Data -----\n\n";
            
            cout << "Cari data berdasarkan apa?\n";
            cout << "1 - Nama\n" << "2 - NIU\n";
            cout << "\nIndeks: ";
            cin >> indexCari;

            hasilCari = -1;

            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

            //Menu Cari Data
            switch (indexCari) {

            case 1 :
                cout << "----- Cari Data Berdasarkan Nama -----\n\n";

                cout << "Nama: ";
                cin >> cariNama;
                cout << endl;

                //Pengecekan array
                for (int i = 0; i < banyakData; i++) {
                    if (nama[i] == cariNama) {
                        hasilCari = i;
                        break;
                    }
                }

                if (hasilCari == -1) {
                    cout << "Data tidak ditemukan\n\n";
                }
                else {
                    cout << "Data Mahasiswa:\n\n";
                    cout << "Nama: " << nama[hasilCari] << endl;
                    cout << "NIU: " << niu[hasilCari] << endl;
                    cout << "Nilai: " << nilai[hasilCari] << "\n\n";
                }                             

                break;

            case 2 :
                cout << "----- Cari Data Berdasarkan NIU -----\n\n";                
                
                cout << "NIU: ";
                cin >> cariNIU;
                cout << endl;
                
                //Pengecekan array
                for (int i = 0; i < banyakData; i++) {
                    if (niu[i] == cariNIU) {
                        hasilCari = i;
                        break;
                    }
                }

                if (hasilCari == -1) {
                    cout << "Data tidak ditemukan\n\n";
                }
                else {
                    cout << "Data Mahasiswa:\n\n";
                    cout << "Nama: " << nama[hasilCari] << endl;
                    cout << "NIU: " << niu[hasilCari] << endl;
                    cout << "Nilai: " << nilai[hasilCari] << "\n\n";
                }

                break;

            default :
                cout << "!!! Index menu tidak valid !!!\n\n";
            }

            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
            break;


        case 5 :
            //Urutkan Data
            cout << "----- Urutkan Data -----\n\n";

            //Pengaturan mengurutkan berdasarkan apa
            cout << "Urutkan data berdasarkan apa?\n";
            cout << "1 - NIU\n" << "2 - Nilai\n" << "3 - Selesai\n";
            cout << "\nIndeks: ";
            cin >> indexSort;
            cout << endl;

            //Pengaturan mengurutkan secara apa
            cout << "Urutkan data secara ascending? (1 untuk ascending, 0 untuk descending)\n";
            cout << "-> ";
            cin >> ascending;
            cout << endl;

            //Urutkan pakai bubble sort algorithm
            urut = false;
            switch (indexSort) {
            case 1 :
                if (ascending) {
                    while (!urut) {
                        urut = true;
                        for (int i = 0; i < banyakData - 1; i++) {
                            if (niu[i] < niu[i + 1]) {
                                //Tukar baris nama
                                tempNama = nama[i];
                                nama[i] = nama[i + 1];
                                nama[i + 1] = tempNama;

                                //Tukar baris niu
                                tempNIU = niu[i];
                                niu[i] = niu[i + 1];
                                niu[i + 1] = tempNIU;

                                //Tukar baris nilai
                                tempNilai = nilai[i];
                                nilai[i] = nilai[i + 1];
                                nilai[i + 1] = tempNilai;

                                urut = false;
                            }
                        }
                    }
                }
                else {
                    while (!urut) {
                        urut = true;
                        for (int i = 0; i < banyakData - 1; i++) {
                            if (niu[i] > niu[i + 1]) {
                                //Tukar baris nama
                                tempNama = nama[i];
                                nama[i] = nama[i + 1];
                                nama[i + 1] = tempNama;

                                //Tukar baris niu
                                tempNIU = niu[i];
                                niu[i] = niu[i + 1];
                                niu[i + 1] = tempNIU;

                                //Tukar baris nilai
                                tempNilai = nilai[i];
                                nilai[i] = nilai[i + 1];
                                nilai[i + 1] = tempNilai;

                                urut = false;
                            }
                        }
                    }
                }
                break;

            case 2 :
                if (ascending) {
                    while (!urut) {
                        urut = true;
                        for (int i = 0; i < banyakData - 1; i++) {
                            if (nilai[i] < nilai[i + 1]) {
                                //Tukar baris nama
                                tempNama = nama[i];
                                nama[i] = nama[i + 1];
                                nama[i + 1] = tempNama;
                                
                                //Tukar baris niu
                                tempNIU = niu[i];
                                niu[i] = niu[i + 1];
                                niu[i + 1] = tempNIU;
                                
                                //Tukar baris nilai
                                tempNilai = nilai[i];
                                nilai[i] = nilai[i + 1];
                                nilai[i + 1] = tempNilai;

                                urut = false;
                            }
                        }
                    }
                }
                else {
                    while (!urut) {
                        urut = true;
                        for (int i = 0; i < banyakData - 1; i++) {
                            if (nilai[i] > nilai[i + 1]) {
                                //Tukar baris nama
                                tempNama = nama[i];
                                nama[i] = nama[i + 1];
                                nama[i + 1] = tempNama;

                                //Tukar baris niu
                                tempNIU = niu[i];
                                niu[i] = niu[i + 1];
                                niu[i + 1] = tempNIU;

                                //Tukar baris nilai
                                tempNilai = nilai[i];
                                nilai[i] = nilai[i + 1];
                                nilai[i + 1] = tempNilai;

                                urut = false;
                            }
                        }
                    }
                }
                break;

            case 3 :
                //Keluar dari menu pengurutan data
                break;

            default :
                cout << "!!! Index menu tidak valid !!!\n\n";                
            }

            cout << "Pengurutan data selesai\n\n";

            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";            
            break;

        case 6 :
            //Hapus Data
            hapusRunning = true;
            while (hapusRunning) {
                cout << "----- Hapus Data -----\n\n";

                cout << "Masukkan nomor urut mahasiswa untuk menghapus datanya\n";
                cout << "Masukkan -1 jika sudah tidak ingin menghapus data\n\n";
                cout << "Nomor Urut: ";
                cin >> nomorUrut;
                cout << endl;

                while (nomorUrut > banyakData) {
                    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                    cout << "Data mahasiswa bernomor urut " << nomorUrut << " belum dientri\n";
                    cout << "Masukkan nomor urut yang valid!\n";
                    cout << "Masukkan -1 jika sudah tidak ingin menghapus data\n\n";
                    cout << "Nomor Urut: ";
                    cin >> nomorUrut;
                    cout << endl;
                }
                nomorUrut--;

                if (nomorUrut == -2) {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                    cout << "Penghapusan data selesai\n\n";
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                    break;
                }
                else {                    
                    for (int i = nomorUrut; i < banyakData - 1; i++) {
                        //Overwrite data dengan data selanjutnya (menghapus, lalu menggeser 1 langkah ke kiri)
                        nama[i] = nama[i + 1];
                        niu[i] = niu[i + 1];
                        nilai[i] = nilai[i + 1];
                    }
                    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                    cout << "Penghapusan data mahasiswa ke-" << nomorUrut + 1 << " berhasil\n\n";
                    banyakData--;
                }                

                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
            }

            break;


        case 7 :
            //Selesai            
            running = false;
            break;


        default :
            cout << "!!! Index menu tidak valid !!!\n\n";

            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        }
    }

    cout << "----- Program Selesai -----\n\n";

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
}
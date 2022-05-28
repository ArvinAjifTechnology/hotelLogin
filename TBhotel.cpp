#include <iostream>
#include <fstream>
#include <string.h>
#include "HOTEL1-1 .h"

using namespace std;

int main (){
	
	int pilih;
	int count;
    char resepsionis[30], customer[30], alamat[50];
    int kamar, no_kamar, harga_kamar, ranjang;
    int total, lama, um, kurang;
    float diskon;
    string jwb, id_customer, id_resepsionis, jk, hp, checkin, checkout, fixkam;
    
	cout<<" Welcome To Penginapan Hotel Hotelan"<<endl;
	cout<<" 1. Login dan Pesan Kamar \n";
	cout<<" 2. Daftar \n";
	cout<<" 3. Lupa Password atau Username\n";
	cout<<"\n Pilih 1 - 3 : ";
	cin>>pilih;
	
	switch (pilih){
		case 1:
			goto login;
			break;
		case 2:
			goto daftar;
			break;
		case 3:
			goto lupa;
			break;
		
		default:
			cout<<" Pilihan tidak ada, silahkan coba lagi !"<<endl;
	}
	
	login:{
		
		string user,pass,u,p;
		
		system("cls");
        cout<<" Username : ";
        cin>>user;
        cout<<" Pasword  :";
        cin>>pass;
        
        ifstream input("database.txt");
        	while(input>>u>>p){
        		
                if(u==user && p==pass){
                    count=1;
                    system("cls");
                }
                
            }
        input.close();
        if(count==1){
        	
            cout<<"\n\n\n\n\n		 Selamat Datang "<<user<<"\n 		Login Akun Berhasil\n";
            cin.get();
            // goto pesan;
            hotel();
            main();
            
                
        }
        else{
            cout<<"\n			    	Login Error\n		Masukkan username dan password yang telah terdaftar\n\n";
            main();
        }
	
	}
	
	daftar:{
		
		string reguser,regpass,ru,rp;
		
        system("cls");
        cout<<"Masukkan username :";
        cin>>reguser;
        cout<<"Masukkan password :";
        cin>>regpass;
        
        ofstream reg("database.txt");
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\n Selamat Registrasi Berhasil\n\n";
        main();
	
	}
	lupa :{
		
		int ch;
        system("cls");
        cout<<"\n Akun anda hilang ?\n\n";
        cout<<" 1. Cari akun dengan username"<<endl;
        cout<<" 2. Cari akun dengan password"<<endl;
        cout<<" 3. Kembali ke menu"<<endl;
        cout<<"\n Pilih 1 - 3 : ";
        cin>>ch;
        switch(ch){
        	
            case 1:{
                int count=0;
                string cariuser,cu,cp;
                cout<<"\n Masukkan username yang Anda ingat : ";
                cin>>cariuser;
                        
                ifstream cari("database.txt");
                while(cari>>cu>>cp){
                    if(cu==cariuser){
                        count=1;
                    }
                }
                cari.close();
                if(count==1){
                    cout<<"\n\n\n\n 		Akun ditemukan\n";
                    cout<<"\n		 Kata sandi Anda adalah : "<<cp;
                    cin.get();
                    cin.get();
                    system("cls");
                    main();
                }
                else{
                    cout<<"\n Maaf, Username Anda tidak ditemukan di database kami\n";
                    cout<<"\n Silakan hubungi administrator sistem untuk lebih jelasnya \n";
                    cin.get();
                    cin.get();
                    main();
                }
            	break;
            }
                case 2:{
                    
					int count=0;
                    string searchpass,su2,sp2;
                    cout<<"\n Masukkan Password yang diingat : ";
                    cin>>searchpass;
                        
                    ifstream searchp("database.txt");
                    while(searchp>>su2>>sp2){
                        if(sp2==searchpass){
                            count=1;
                        }       
                    }
                    searchp.close();
                    if(count==1){
                    	
                        cout<<"\n\n\n\n 		Akun ditemukan \n";
                        cout<<"\n 		Username Anda adalah : "<<su2;
                        cin.get();
                        cin.get();
                        system("cls");
                        main();
                    }
                    else{
                        cout<<"\n Maaf, Kami tidak dapat menemukan kata sandi Anda di database kami \n";
                        cout<<"\n silakan hubungi administrator untuk informasi lebih lanjut\n";
                        cin.get();
                        cin.get();
                        main();
                    }
                
                    break;
                }
                
                case 3:
                {
                	cin.get();
                    main();
                }
                default:
                        cout<<" Maaf, Anda salah memasukkan pilihan. Silakan coba lagi"<<endl;
                        goto lupa;
        }
	
	}
pesan:
    cout<<"\n\t\t             ========================================================";
    cout<<"\n\t\t           ==============================================================";
    cout<<"\n\t\t        ====================================================================";
    cout<<"\n\t\t      =========================================================================";
    cout<<"\n\t\t   ==============================================================================";
    cout<<"\n\t\t                        SELAMAT DATANG DI HOTEL HOTELAN                  ";
    cout<<"\n\n\t\t                  JL. Sama kamu itu mimpi, no 1 tapi di duain              ";
    cout<<"\n\t\t                       Tetap Semangat walau masih Jomblo             ";
     cout<<"\n\t\t=================================================================================";
     cout<<"\n\t\t=================================================================================";
               
                cout<<"\n\n\n\n\t\tForm Hotel Hotelan Silahkan Di isi";
cout<<"\n\t\t=================================================================================";cout<<endl;
                cout<<"\t\tNama Resepsionis Yang Melayani : "; gets(resepsionis);
                cout<<"\t\tID Resepsionis                 : "; cin>>id_resepsionis;
                cout<<"\t\tNama Pemesan                   : "; cin>>customer;
                cout<<"\t\tID Pemesan                     : "; cin>>id_customer;
                cout<<"\t\tJenis Kelamin [L/P]            : "; cin>>jk;
                cout<<"\t\tNomor Telepon/HP               : "; cin>>hp;
                cout<<"\t\tAlamat Pemesan                 : "; cin>>alamat;
      cout<<"\t\t=================================================================================";
               
                cout<<"\n\n\t\t Silahkan Pilih  Variasi Kamar";
  cout<<"\n\t\t=================================================================================";
                cout<<"\n\t\t1. Standar (seadanya)";
                cout<<"\n\t\t2. Premium (Komplit)";

  cout<<"\n\t\t=================================================================================";
                cout<<"\n\t\tMasukan Pilihan : ";cin>>kamar;
               
                cout<<"\n\n\t\tJumlah Kasur yang anda inginkan";
  cout<<"\n\t\t=================================================================================";
                cout<<"\n\t\t1. Single";
                cout<<"\n\t\t2. Double";
  cout<<"\n\t\t=================================================================================";
                cout<<"\n\t\tPilih Jumlah kasur : ";cin>>ranjang;cout<<endl;
               
                if(kamar==1 && ranjang==1)
                {
                                cout<<"\n\t\tAnda Memilih Kamar Bertipe Standar (seadanya) Dengan Jumlah Kasur Single";
                                fixkam="Standart Dengan Single Bed";
                                harga_kamar=200000;
                }
                else if(kamar==1 && ranjang==2)
                {
                    cout<<"\n\t\tAnda Memilih Kamar Bertipe Standar (seadanya) Dengan Jumlah Kasur Double";
                    fixkam="Standart Dengan Double Bed";
                                harga_kamar=250000;                  
                }
                else if(kamar==2 && ranjang==1)
                {
                    cout<<"\n\t\tAnda Memilih Kamar Tipe Premium (komplit) Dengan Jumlah Kasur single";
                    fixkam="Premium Dengan Single Bed";
                                harga_kamar=450000;                  
                }
                else if(kamar==2 && ranjang==2)
                {
                    cout<<"\n\t\tAnda Memilih Kamar Tipe Premium (komplit) Dengan Jumlah Kasur Double";
                    fixkam="Premium Dengan Double Bed";
                                harga_kamar=500000;                  
                }
                else
                {
                                cout<<"\n\t\tMaaf Pilihan Anda Tidak Tersedia";
                                cout<<"\n\t\tUntuk Keamanan Silahkan Isi Data Dari Awal";
                                cout<<"\n\t\tApakah Anda Ingin Memulai Lagi ? [Y/N]";cin>>jwb;
                                if(jwb=="Y" || "y")
                                {
                                                goto pesan;
                                }
                                else
                                {
                                                cout<<"\n\n\t\tTerima Kasih";
                                }
                }
                cout<<"\n\n\n\t\tSilahkan isi Form kedua Berikut";
  cout<<"\n\t\t=================================================================================";
                cout<<"\n\t\tPilih No. Kamar yang di inginkan [1-100]     : "; cin>>no_kamar;
                cout<<"\n\t\tJika anda menginap Lebih Dari 5 Hari akan dapat diskon 2% perhari";
                cout<<"\n\t\tLama Menginap               : "; cin>>lama;
               
                if(lama>=5)
                {
                                diskon=0.2;
                }
                else
                {
                                diskon=0;
                }
                cout<<"\n\t\tTanggal Check In [DD/MM/YYYY]   : ";cin>>checkin;
                cout<<"\n\t\tTanggal Check Out [DD/MM/YYYY]  : ";cin>>checkout;
                
      cout<<"\t\t=================================================================================";
               
                cout<<"\n\n\n\n\t\tData Pemesanan Hotel Hotelan"<<endl;
      cout<<"\t\t=================================================================================";
                cout<<"\n\t\tNama Resepsionis : "<<resepsionis;
                cout<<"\n\t\tID Resepsionis   : "<<id_resepsionis;
                cout<<"\n\t\tNama Pemesan     : "<<customer;
                cout<<"\n\t\tID Pemesan       : "<<id_customer;
                cout<<"\n\t\tAlamat Pemesan   : "<<alamat;
                cout<<"\n\t\tNo Telp/HP       : "<<hp;
                cout<<"\n\t\tTipe Kamar       : "<<fixkam;
                cout<<"\n\t\tNo. Kamar        : ";
                if(no_kamar >= 1 && no_kamar <= 100)
                {
                                cout<<no_kamar;
                }
                else
                {
                                cout<<"\n\t\tMaaf Nomer Kamar Belum Tersedia";
                                cout<<"\n\t\tSilahkan Hubungi Resepsionis Untuk Pergantian Nomer";
                }
                cout<<"\n\t\tLama Menginap    : "<<lama<<" Hari";
                cout<<"\n\t\tTanggal Check in : "<<checkin;
                cout<<"\n\t\tTanggal Check out: "<<checkout;
                cout<<"\n\t\tHarga Perhari    : Rp. "<<harga_kamar;
                cout<<"\n\t\tHarga Kamar Total: Rp. "<<lama*harga_kamar;
                cout<<"\n\t\tDiskon           : Rp. "<<diskon*harga_kamar<<endl;
                total=harga_kamar*lama-(diskon*harga_kamar);
      cout<<"\t\t=================================================================================";
                cout<<"\n\n\t\tBiaya Total      : Rp. "<<total;
                cout<<"\n\t\tUang Muka        : Rp. ";cin>>um;
                kurang=total-um;
                if(total>=um)
                {
                                cout<<"\n\t\tKekurangan       : Rp. "<<kurang;
                }
                else
                {
                                cout<<"\n\t\tKembali          : Rp. "<<kurang*(-1);
                }
  cout<<"\n\t\t=================================================================================";
               
                cout<<"\n\n\t\tTerima Kasih Telah Memilih Hotel Hotelan";
                cout<<"\n\t\tSebagai Tempat Penginapan yang nyaman untuk anda :)";
                cout<<endl;
                cout<<"\n\n\t\tApakah Anda Ingin Memesan Kamar Lagi ? [y/n]";cin>>jwb;
                if(jwb=="Y" || jwb=="y")
                {
                                goto pesan;
                }
                else
                {
                                cout<<"\n\n\t\tTerima Kasih Atas Kunjungannya";
                }
}

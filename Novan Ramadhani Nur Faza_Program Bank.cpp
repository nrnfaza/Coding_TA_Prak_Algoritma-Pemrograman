/*
Novan Ramadhani Nur Faza   (140110210020)
Fachrul Ananda Putra       (140110210008)
Aulya Putri                (140110210033)
Humam Siddiq Aminullah     (140110210034)
Hanifah Al Affiani         (140110210049)
*/

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>

using namespace std;

struct identitas
{
    long int no_rekening, saldo, cicil, setor,tarik, ccl, t_t, t_s, transfer, terima, tt, ts, tpp;
    char nama[50], alamat[100];
    float bunga;
    double sisacicilan;
};

struct admlog
{
    char r[100];
    string e;
};

 int a=0, q, n, t, jumlah, x=1, input, men, ma, mn, mc, pinjaman, bulan;
 char jawab, lagi, inu[100];
 long int nw, tip;
 double totalCicilan, bunge, pembayaran, cicilanPerBulan;
 admlog al;
 identitas id[100];

void menu();
void adminlog();
void admin();
void inp();
void daftar();
void laporan();
void user();
void setoran();
void penarikan();
void transfer();
void top();
void tp();
void cicil();
void pu();
void rincian();
void bc();

int main()
{
    system("color 1f");
    menu();
}

void menu()
{
    system("cls");
    cout<<"+==========================+\n";
    cout<<"|       Program Bank       |\n";
    cout<<"+==========================+\n";
    cout<<"\n";
    cout<<"+==================================+\n";
    cout<<"| 1. Menu Admin Bank               |\n";
    cout<<"| 2. Menu Nasabah                  |\n";
    cout<<"| 3. Exit                          |\n";
    cout<<"+==================================+\n";
    cout<<"\nPilih Menu 1/2/3 : ";cin>>men;
    if (men==1){adminlog();}
    else if (men==2){user();}
    else if(men==3){exit(0);}
    else if(men>3){menu();}
}

void adminlog()
{
    system("cls");
    cout<<"\n+==================================+\n";
    cout<<"|          Login Admin Bank        |\n";
    cout<<"+==================================+\n";
    cout<<"Input Username: ";cin>>al.r;
    cout<<"Input Password: ";cin>>al.e;
    if(al.e==strrev(al.r))
    {
        cout<<"Login Berhasil." <<endl;
        system("pause");
        admin();
    }
    else
    {
        cout<<"Password yang Anda masukan salah. Silahkan ulang kembali."<<endl;
        getch();
        adminlog();
    }
}

void admin()
{
    system("cls");
    cout<<"\n+==================================+\n";
    cout<<"|          Menu Admin Bank         |\n";
    cout<<"+==================================+\n";
    cout<<"| 1. Input Data Nasabah            |\n";
    cout<<"| 2. List Nasabah                  |\n";
    cout<<"| 3. Laporan Penarikan dan Setoran |\n";
    cout<<"| 4. Exit                          |\n";
    cout<<"+==================================+\n";
    cout<<"\n";
    cout<<"Pilih Menu 1/2/3/4 : ";cin>>ma;
    switch (ma)
    { //awal case of ma

    case 1: {inp();}
    case 2: {daftar();}
    case 3: {laporan();}
    case 4: {menu();}
    }
}

void inp()
{
    bool ketemu=false;
    system("cls");
    cout<<"+==================================+\n";
    cout<<"|        Input Data Nasabah        |\n";
    cout<<"+==================================+\n";
    cout<<"Nomor Rekening    : ";cin>>nw;
    for(n=0; n<a; n++)
    {
        if(nw==id[n].no_rekening)
        ketemu=true;
        else
        ketemu=false;
    }
    if(ketemu)
    {
        cout<<"\nNomer Rekening Tersebut Sudah Ada, Ulangi Lagi"<<endl;
        system("pause");
        inp();
    }
    else{
    cout<<"Nama              : ";cin>>id[n].nama;
    cout<<"Alamat            : ";cin>>id[n].alamat;
    cout<<"Masukan Saldo awal: Rp.";cin>>id[n].saldo;
    cout<<"\n";
    cout<<"+=================================+\n";
    cout<<"|     Data berhasil diproses      |\n";
    cout<<"|                                 |\n";
    cout<<"|           Terima kasih          |\n";
    cout<<"+=================================+\n";
    }
    a=a+1;
    id[n].no_rekening=nw;
    ask:
    cout<<"Input Data Nasabah Selanjutnya ? (y/t) : ";cin>>lagi;
    if (lagi=='y' || lagi=='Y'){inp();}
    else if (lagi=='t' || lagi=='T'){admin();}
    else
    {
     cout<<"Input salah !!! \n";
     goto ask;
    }
    getch();
}


void daftar()
{
    system("cls");
    cout<<"+===========================================+\n";
    cout<<"|                 List Nasabah              |\n";
    cout<<"+===========================================+\n";

    cout<<"|====|=================|==============|==============|=================|"<<endl;
    cout<<"| No |   No Rekening   |     Nama     |    Alamat    |   Total Saldo   |"<<endl;
    cout<<"|====|=================|==============|==============|=================|"<<endl;

    for (n=0;n<a;n++)
    {
     cout<<setw(4)<<(n+1);
     cout<<setw(16)<<id[n].no_rekening;
     cout<<setw(13)<<id[n].nama;
     cout<<setw(16)<<id[n].alamat;
     cout<<setw(18)<<id[n].saldo<<endl;
     cout<<"|======================================================================|\n";

    }
       cout<<"\nKembali ke List Nasabah ? (y/t) : ";cin>>jawab;
       if (jawab=='y' || jawab=='Y'){daftar();}
       else if (jawab=='t' || jawab=='T'){admin();}
       else
       {
           cout<<"Input salah !!! \n";
           getch();
           daftar();
       }
    getch();
}

void laporan()
{
    system("cls");
    cout<<"+=================================+\n";
    cout<<"|  Laporan Penarikan dan Setoran  |\n";
    cout<<"+=================================+\n";
    cout<<"  \n";
    for (n=0;n<a;n++)
    { cout<<"+===========================================+\n";
     cout<<"No.              : "<<(n+1)<<endl;
     cout<<"Nomor Rekening   : "<<id[n].no_rekening<<endl;
     cout<<"Nama Lengkap     : "<<id[n].nama<<endl;
     cout<<"Alamat           : "<<id[n].alamat<<endl;
     cout<<"Total Setoran    : Rp."<<id[n].t_s<<endl;
     cout<<"Total Penarikan  : Rp."<<id[n].t_t<<endl;
     cout<<"Total Transfer   : Rp."<<id[n].ts<<endl;
     cout<<"Total Terima     : Rp."<<id[n].tt<<endl;
     cout<<"Total Top Up     : Rp."<<id[n].tpp<<endl;
     cout<<"Total Cicilan    : Rp."<<id[n].ccl<<endl;
     cout<<"Sisa Cicilan     : Rp."<<id[n].sisacicilan<<endl;
     id[n].bunga=id[n].saldo*0.05;
     cout<<"Bunga (5%/bulan) : Rp."<<id[n].bunga<<endl;
     cout<<"Sisa Saldo       : RP."<<id[n].saldo<<endl;
     cout<<" \n";
     cout<<"+===========================================+\n";
    }
    cetak:
    cout<<"\nCetak Laporan ? (y/t) : ";cin>>jawab;
    {
     if (jawab=='y'||jawab=='Y')
      {
       system("cls");
       for (n=0;n<a;n++)
       {
        cout<<"================================================================================\n";
        cout<<"No.              : "<<(n+1)<<endl;
        cout<<"Nomor Rekening   : "<<id[n].no_rekening<<endl;
        cout<<"Nama Lengkap     : "<<id[n].nama<<endl;
        cout<<"Alamat           : "<<id[n].alamat<<endl;
        cout<<"Total Setoran    : Rp."<<id[n].t_s<<endl;
        cout<<"Total Penarikan  : Rp."<<id[n].t_t<<endl;
        cout<<"Total Transfer   : Rp."<<id[n].ts<<endl;
        cout<<"Total Terima     : Rp."<<id[n].tt<<endl;
        cout<<"Total Top Up     : Rp."<<id[n].tpp<<endl;
        cout<<"Total Cicilan    : Rp."<<id[n].ccl<<endl;
        cout<<"Sisa Cicilan     : Rp."<<id[n].sisacicilan<<endl;
        cout<<"Bunga (5%/bulan) : Rp."<<id[n].bunga<<endl;
        cout<<"Sisa Saldo       : RP."<<id[n].saldo<<endl;
        cout<<" \n";
        cout<<"================================================================================\n";
       }
      }
     else if (jawab=='t'||jawab=='T'){admin();}
     else
      {
       cout<<"\nInput Salah !!!";
       goto cetak;
      }
    }
    tanya1:
    cout<<"\nKeterangan :";
    cout<<"\n(Y/y) = untuk kembali ke menu admin bank";
    cout<<"\n(T/t) = untuk kembali ke menu utama";
    cout<<"\nKembali Ke Menu Admin ? (y/t) : ";cin>>jawab;
    if (jawab=='y' || jawab=='Y'){admin();}
    else if (jawab=='t' || jawab=='T'){menu();}
    else
    {
     cout<<"\nPilihan tidak ada !!!\n";
     goto tanya1;
    }
    getch();
}

void user()
{
    system("cls");
    cout<<"\nMasukan Nomor Rekening : ";cin>>input;
    for (n=0;n<=a;n++)
    {
     if (input==id[n].no_rekening)
     {

      system("cls");
      cout<<"\n+==================================+\n";//tampilan awal menu nasabah
      cout<<"|            Menu Nasabah          |\n";
      cout<<"|==================================|\n";
      cout<<"| 1. Setoran                       |\n";
      cout<<"| 2. Penarikan                     |\n";
      cout<<"| 3. Transfer                      |\n";
      cout<<"| 4. Top up                        |\n";
      cout<<"| 5. Pembayaran Cicilan            |\n";
      cout<<"| 6. Exit                          |\n";
      cout<<"+==================================+\n";
      cout<<"\n";
      cout<<"\nMasukan Pilihan 1/2/3/4/5/6  : ";cin>>mn;
      switch (mn)
      {
      case 1:{setoran();}
      case 2:{penarikan();}
      case 3:{transfer();}
      case 4:{top();}
      case 5:{cicil();}
      case 6:{menu();}
      default:
        {
         cout<<"Menu yang anda pilih tidak ada !!!\n";
         getch();
         user();
        }
      }
     }
    }
    cout<<"\nNomor Rekening Salah !!!\n";
    getch();
    user();
}

void setoran()
{//awal menu nasabah 1
    system("cls");
     cout<<"+=================================+\n";
     cout<<"|            Penyetoran           |\n";
     cout<<"+=================================+\n";
     cout<<"\n";
     cout<<"+==================================+\n";
     cout<<"|        Detail Data Nasabah       |\n";
     cout<<"+==================================+\n";
     cout<<"Nomor Rekening : "<<id[n].no_rekening<<endl;
     cout<<"Nama Lengkap   : "<<id[n].nama<<endl;
     cout<<"Alamat         : "<<id[n].alamat<<endl;
     cout<<"Jumlah Saldo   : Rp."<<id[n].saldo<<endl;
     cout<<"\n";
     cout<<"Masukan Jumlah Uang yang akan disetor : Rp.";cin>>id[n].setor;
     cout<<"\n";
        {
         if (id[n].setor<20000)
          {
           system("cls");
           cout<<"+=============================================+\n";
           cout<<"|    Maaf setoran anda tidak dapat di proses  |\n";
           cout<<"|            Minimal setoran Rp.20.000        |\n";
           cout<<"+=============================================+\n";
          }
         else
          { id[n].saldo=id[n].setor+id[n].saldo;
           id[n].t_s=id[n].setor+id[n].t_s;
           system("cls");
           cout<<"+=================================+\n";
           cout<<"|    Setoran berhasil diproses    |\n";
           cout<<"+=================================+\n";
           cout<<"\n"<<endl;
           cout<<"Jumlah saldo anda : Rp."<<id[n].saldo;
           cout<<"\n"<<endl;
          }
        }
     tanya2:
     cout<<"\n (Y/y) = Kembali Ke Menu Nasabah";
     cout<<"\n (T/t) = Kembali Ke Menu Utama";
     cout<<"\nKembali Ke Menu Nasabah ? (y/t) : ";cin>>jawab;
     if (jawab=='y' || jawab=='Y'){user();}
     else if (jawab=='t' || jawab=='T'){menu();}
     else
      {
       cout<<"\nPilihan tidak ada !!!\n";
       goto tanya2;
      }
     getch();
}//akhir menu nasabah 1

void penarikan()
{//awal menu nasabah 2
    system("cls");
    cout<<"+=================================+\n";
    cout<<"|             Penarikan           |\n";
    cout<<"+=================================+\n";
    cout<<"\n";
    cout<<"+==================================+\n";
    cout<<"|        Detail Data Nasabah       |\n";
    cout<<"+==================================+\n";
    cout<<"Nomor Rekening : "<<id[n].no_rekening<<endl;
    cout<<"Nama Lengkap   : "<<id[n].nama<<endl;
    cout<<"Alamat         : "<<id[n].alamat<<endl;
    cout<<"Jumlah Saldo   : Rp."<<id[n].saldo<<endl;
    cout<<"\n";
    cout<<"Masukan Jumlah Uang yang akan ditarik : Rp.";cin>>id[n].tarik;
    cout<<"\n";
     if (id[n].saldo-id[n].tarik<10000)
      { system("cls");
       cout<<"+=====================================+\n";
       cout<<"|   Maaf Saldo Anda Tidak Mencukupi   |\n";
       cout<<"|     Sisa Saldo Minimal Rp.10.000    |\n";
       cout<<"+=====================================+\n";
      }
     else
      {
       id[n].saldo=id[n].saldo-id[n].tarik;
       id[n].t_t=id[n].tarik+id[n].t_t;
       system("cls");
       cout<<"+=================================+\n";
       cout<<"|   Penarikan berhasil diproses   |\n";
       cout<<"|     Silahkan Ambil Uang Anda    |\n";
       cout<<"+=================================+\n";
       cout<<"\n"<<endl;
       cout<<"Sisa saldo anda : Rp."<<id[n].saldo;
       cout<<"\n"<<endl;
      }
    cout<<"\n (Y/y) = Kembali Ke Menu Nasabah";
    cout<<"\n (T/t) = Kembali Ke Menu Utama";
    cout<<"\nKembali Ke Menu Nasabah ? (y/t) : ";cin>>jawab;
    if (jawab=='y' || jawab=='Y'){user();}
    if (jawab=='t' || jawab=='T'){menu();}
    getch();
}//akhir menu nasabah 2

void transfer()
{//awal menu nasabah 3
    system("cls");
    cout<<"+=================================+\n";
    cout<<"|             Transfer            |\n";
    cout<<"+=================================+\n";
    mn4:
    cout<<"\nMasukan Nomor Rekenig Tujuan : ";cin>>input;
    for (t=0;t<=a;t++)
    {
    if (input==id[t].no_rekening)
    {
     cout<<"\n+===================================================+\n";
     cout<<"Nomor Rekening : "<<id[t].no_rekening<<endl;
     cout<<"Nama Lengkap   : "<<id[t].nama<<endl;
     cout<<"Alamat         : "<<id[t].alamat<<endl;
     cout<<"\nMasukan jumlah Transfer : Rp.";cin>>id[t].transfer;
     tanya5:
     cout<<"\nData Sudah Benar ?";
     cout<<"\nProses Transfer ? (y/t) : ";cin>>jawab;
     if (jawab=='y' || jawab=='Y')
     {
      if (id[n].saldo-id[t].transfer<20000)
      { system("cls");
       cout<<"+=====================================+\n";
       cout<<"|   Maaf Saldo Anda Tidak Mencukupi   |\n";
       cout<<"|     Sisa Saldo Minimal Rp.20.000    |\n";
       cout<<"+=====================================+\n";
      }
      else
      { id[n].saldo=id[n].saldo-id[t].transfer;
       id[t].saldo=id[t].transfer+id[t].saldo;
       id[t].tt=id[t].transfer+id[t].tt;
       id[n].ts=id[t].transfer+id[n].ts;
       system("cls");
       cout<<"+=====================================+\n";
       cout<<"|     Transfer Berhasil Diperoses     |\n";
       cout<<"|             Terima Kasih            |\n";
       cout<<"+=====================================+\n";
       cout<<"\n Sisa Saldo : "<<id[n].saldo<<endl;
      }
      tanya7:
      cout<<"\n+=================================+\n";
      cout<<"\nKeterangan =";
      cout<<"\n(Y/y)  = Kembali Ke Menu Nasabah";
      cout<<"\n(T/t)  = Kembali Ke Menu Utama";
      cout<<"\nKembali ke Menu Nasabah ? (y/t) : ";cin>>jawab;
      if (jawab=='y'||jawab=='Y'){user();}
      else if (jawab=='t'||jawab=='T'){menu();}
      else
       {
        cout<<"\nInput Salah !!!\n";
        goto tanya7;
       }
     }
     else if (jawab=='t'||jawab=='T')
     {
      tanya8:
      cout<<"\n+=================================+\n";
      cout<<"\nKeterangan =";
      cout<<"\n(Y/y)  = Kembali Ke Menu Nasabah";
      cout<<"\n(T/t)  = Kembali Ke Menu Utama";
      cout<<"\nKembali ke Menu Nasabah ? (y/t) : ";cin>>jawab;
      if (jawab=='y'||jawab=='Y'){user();}
      else if (jawab=='t'||jawab=='T'){menu();}
      else
       {
        cout<<"\nInput Salah !!!\n";
        goto tanya8;
       }
     }
     else
     {
      cout<<"\nInput Salah !!!\n";
      getch();
      transfer();
     }
    }
    }
    cout<<"\nNomor Rekening tidak terdaftar !!!\n";
    tanya6:
    cout<<"\nKembali Ke Menu ? (y/t) : ";cin>>jawab;
    if (jawab=='y'||jawab=='Y'){user();}
    else if (jawab=='t'||jawab=='T'){goto mn4;}
    else
    {
    cout<<"\nInput Salah !!!\n";
    goto tanya6;
    }
    getch();
}//akhir menu nasabah 3

void top()
{//awal menu nasabah 4
    system("cls");
    cout<<"+=================================+\n";
    cout<<"|             Top up              |\n";
    cout<<"+=================================+\n";
    cout<<"1. OVO\n";
    cout<<"2. Gopay\n";
    cout<<"3. Dana\n";
    cout<<"Silahkan Masukan Pilihan Anda [1/2/3]: "; cin>>jawab;
    tp();
}

void tp()
{
    system("cls");
    cout<<"\nMasukan Nomor Tujuan : ";cin>>inu;
    cout<<"Masukan Jumlah yang ingin di Top Up: Rp.";cin>>tip;
    if(tip>=10000)
    {
        if(tip<=id[n].saldo)
        {
        id[n].saldo=id[n].saldo-tip;
        id[n].tpp=id[n].tpp+tip;
        cout<<"Top Up ke nomor "<<inu<<" Sebesar Rp."<<tip<<" Berhasil"<<endl;
        }
        else{cout<<"Top Up Gagal"<<endl;}
    }
    else
    {
        cout<<"Maaf Saldo yang anda masukan Kurang dari Rp.10000"<<endl;
        cout<<"Keluar dari laman Top Up (Y/T)?";cin>>jawab;
        if (jawab=='Y'||jawab=='y'){user();}
        else{tp();}

    }
      cout<<"\n+=================================+\n";
      cout<<"\nKeterangan =";
      cout<<"\n(Y/y)  = Kembali Ke Menu Nasabah";
      cout<<"\n(T/t)  = Kembali Ke Menu Utama";
      cout<<"\nKembali ke Menu Nasabah ? (y/t) : ";cin>>jawab;
      if (jawab=='y'||jawab=='Y'){user();}
      else if (jawab=='t'||jawab=='T'){menu();}
}//akhir menu nasabah 4

void cicil()
{
    system("cls");
    cout<<"+==================================+\n";
    cout<<"|              Cicil               |\n";
    cout<<"+==================================+\n";
    cout<<"1. Pinjam Uang\n";
    cout<<"2. Rincian Cicilan\n";
    cout<<"3. Bayar Cicilan\n";
    cout<<"4. Keluar\n";
    cout<<"Pilih salah satu pilihan di atas (1/2/3/4): "; cin>>mc;
    switch(mc)
    {
    case 1:
        pu();
    case 2:
        rincian();
    case 3:
        bc();
    case 4:
        user();
    }
}

void pu()
{
    system("cls");
    cout<<"+==================================+\n";
    cout<<"|           Pinjam Uang            |\n";
    cout<<"+==================================+\n";
    cout<<"\nMasukan Total Pinjaman: ";cin>>pinjaman;
    if(pinjaman<=id[n].saldo)
    {
    cout << "=======================================\n";
	cout << "pilihan lama cicilan (perbulan)\n";
	cout << "1. 6 bulan dengan bunga 0.7%\n";
	cout << "2. 12 bulan dengan bunga 0.8%\n";
	cout << "3. 18 bulan dengan bunga 0.9%\n";
	cout << "4. 24 bulan dengan bunga 1.0 %\n";
	cout << "=======================================\n";
	cout << "Pilih lama cicilan : "; cin >> q;

    while(q < 1 || q > 4){
		cout << "Tidak ada dalam pilihan, masukan ulang : "; cin >> a;
	}

	switch (q){
		case 1 :bulan = 6;bunge=0.7;break;
		case 2 :bulan = 12;bunge=0.8;break;
		case 3 :bulan = 18;bunge=0.9;break;
		case 4 :bulan = 24;bunge=1;break;
	}
	totalCicilan = pinjaman + (pinjaman * bunge/100);

	rincian();
    }
    else
    {
        cout<<"Maaf Pinjaman Terlalu Besar"<<endl;
        cout<<"Kembali Ke Pinjaman (Y/T)? ";cin>>jawab;
        if(jawab=='Y'||jawab=='y'){pu();}
        else{cicil();}
    }

}
void rincian()
{
    system("cls");
	cout << "=====================[Rincian]====================\n";
	cout << "Nama                     : " << id[n].nama << endl;
	cout << "Alamat                   : " << id[n].alamat << endl;
	cout << "lama cicilan             : " << bulan << " bulan" << endl;
	cout << "Peminjaman               : " << pinjaman << endl;
	cout << "Bunga (%)                : " << bunge << "%" << endl;
	cout << "Bunga (Rupiah)           : " << (pinjaman * bunge/100) << endl;
	cout << "Estimasi Total Cicilan   : " << totalCicilan << endl;
	cout << "cicilan perbulan sebesar : " << totalCicilan/bulan << endl;
	id[n].saldo=id[n].saldo+pinjaman;
	cout << "\nKembali Ke Laman Cicil (Y/T)? ";cin>>jawab;
	if(jawab=='Y'||jawab=='y'){cicil();}
    else{rincian();}
}

void bc()
{
    system("cls");
    do
	{
		cicilanPerBulan = totalCicilan/bulan;
		system("cls");
		cout<<"+======================================+\n";
        cout<<"|            Bayar Cicilan             |\n";
        cout<<"+======================================+\n";

		cout << "\nPembayaran Cicilan ke-" << x << " : "; cin >> pembayaran;
		if(pembayaran>=id[n].saldo)
        {
            cout<<"Maaf Saldo Anda Tidak Mencukupi"<<endl;
            getch();
            bc();
        }
        else if(pembayaran<id[n].saldo)
        {
            if(pembayaran < cicilanPerBulan)
            {
			cout << "Uang kurang, masukan kembali : "; cin >> pembayaran;
            }

            else if (pembayaran > cicilanPerBulan)
            {
            cout << "Kembalian : " << pembayaran - cicilanPerBulan << endl;
            id[n].saldo=id[n].saldo-cicilanPerBulan;
            id[n].ccl=id[n].ccl+cicilanPerBulan;
            }
            x++;
            jumlah += cicilanPerBulan;
            id[n].sisacicilan = totalCicilan - jumlah;
            cout << "sisa pembayaran : " << id[n].sisacicilan << endl;

            cout << "sisa waktu cicilan : " << (bulan - x) + 1 << endl;
            cout << "Ingin Kembali ke Laman Cicilan (Y/T)? "; cin>>jawab;
            while(jawab=='Y'||jawab=='y'){cicil();}
        }
	} while (x <= bulan);
	cout << endl;
	if ((totalCicilan - jumlah) < 0){
		cout << "Cicilan tidak lunas" << endl;
		system("pause");
	}else{
		cout << "Cicilan lunas" << endl;
		system("pause");
	}
}

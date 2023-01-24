# Penyelesaian Permainan Kartu 24 dengan Algoritma Brute Force"
Tugas Kecil 1 - Strategi Algoritma 2022/2023

Disusun oleh: Eugene Yap Jin Quan (13521074) - IF2211-02 (2022/2023)

### Deskripsi Singkat
> Permainan kartu 24 adalah permainan kartu aritmatika dengan tujuan mencari cara untuk mengubah 4 buah angka random sehingga mendapatkan hasil akhir sejumlah 24. Permainan ini menarik cukup banyak peminat dikarenakan dapat meningkatkan kemampuan berhitung serta mengasah otak agar dapat berpikir dengan cepat dan akurat. Permainan Kartu 24 biasa dimainkan dengan menggunakan kartu remi. Kartu remi terdiri dari 52 kartu yang terbagi menjadi empat suit (sekop, hati, keriting, dan wajik) yang masing-masing terdiri dari 13 kartu (As, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, dan King). Yang perlu diperhatikan hanyalah nilai kartu yang didapat (As, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, dan King). As bernilai 1, Jack bernilai 11, Queen bernilai 12, King bernilai 13, sedangkan kartu bilangan memiliki nilai dari bilangan itu sendiri. Pada awal permainan moderator atau salah satu pemain mengambil 4 kartu dari dek yang sudah dikocok secara random. Permainan berakhir ketika pemain berhasil menemukan solusi untuk membuat kumpulan nilainya menjadi 24. Pengubahan nilai tersebut dapat dilakukan menggunakan operasi dasar matematika penjumlahan (+), pengurangan (-), perkalian (×), divisi (/) dan tanda kurung ( () ). Tiap kartu harus digunakan tepat sekali dan urutan penggunaannya bebas.

>Sumber: https://informatika.stei.itb.ac.id/~rinaldi.munir/Stmik/2015-2016/Makalah2016/MakalahStima-2016-038.pdf).


Program ini digunakan untuk mencari solusi permainan kartu 24 berdasarkan masukan 4 nilai kartu (A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K) dan menyimpan solusi dalam bentuk file text. Masukan dapat berupa input manual atau random. Program ini diimplementasikan menggunakan algoritma *brute force* sebagai salah satu tugas dari mata kuliah IF2211 Strategi Algoritma.

### Requirements
Pastikan compiler GCC/G++ sudah terpasang pada sistem operasi Anda. Pada Linux, lakukan juga pemasangan `build-essential`.

### Instalasi
1. Lakukan clone repo
```
git clone https://github.com/Eugene316/Tucil1_13521074.git
```
2. Pada direktori utama, buka terminal.

3. Jalankan perintah berikut.

Windows:

```
g++ .\src\main.cpp .\src\expr.cpp .\src\solver.cpp .\src\utils.cpp -o .\bin\24_game_solver
```

Linux: 

```
g++ ./src/main.cpp ./src/expr.cpp ./src/solver.cpp ./src/utils.cpp -o ./bin/24_game_solver
```

4. Sebagai alternatif, jalankan script `.\setup.ps1` untuk Windows. Untuk Linux, jalankan `./setup.sh`


### Cara Menjalankan Program
0. Lakukan instalasi/kompilasi terhadap program.

1. Pada direktori utama, buka terminal.

2. Jalankan perintah berikut.

Windows:

```
cd bin

.\24_game_solver.exe

cd ..
```

Linux: 

```
cd bin

./24_game_solver
```

3. Sebagai alternatif, jalankan script `.\play.ps1` untuk Windows. Untuk Linux, jalankan `./play.sh`

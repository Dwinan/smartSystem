🚧 Deteksi dan Peringatan Gas dengan Aksi Relai Mengendalikan LED
Proyek ini bertujuan untuk mendeteksi potensi bahaya gas menggunakan sensor MQ dan memberikan peringatan suara melalui buzzer. Sebagai simulasi dari aksi pencegahan kebakaran, modul relay akan secara langsung mengendalikan sebuah LED, merepresentasikan bagaimana relay dapat menghidupkan atau mematikan perangkat eksternal dengan daya yang lebih tinggi.

🔧 Komponen yang Digunakan
1x Sensor Gas MQ-2 (atau MQ-7 seperti pada gambar)
1x Board Arduino Uno (sesuai gambar)
1x Modul Buzzer (Aktif/Pasif)
1x Modul Relay 1-Channel
1x LED (warna bebas, misal merah)
1x Resistor 220 Ohm (untuk LED)
Kabel Jumper
Breadboard (opsional, untuk prototipe)

🔌 Pengkabelan (Wiring)
Komponen Pin Sensor Pin Arduino
Sensor Gas MQ VCC 5V
GND GND
AO (Analog) A0
Buzzer VCC 5V
GND GND
S (Signal) D9
Modul Relay VCC 5V
GND GND
IN D7
Koneksi LED melalui Relay: COM (Common) Relay 5V Arduino
NO (Normally Open) Relay Anoda (+) LED
Katoda (-) LED Resistor 220 Ohm, lalu ke GND Arduino

Penjelasan Koneksi LED ke Relay:

5V Arduino dihubungkan ke pin COM (Common) pada modul relay. Ini adalah sumber daya yang akan dialirkan oleh relay.
Anoda (+) LED dihubungkan ke pin NO (Normally Open) pada modul relay. Ini adalah terminal output yang akan terhubung ke COM saat relay diaktifkan.
Katoda (-) LED dihubungkan secara seri dengan Resistor 220 Ohm, kemudian Resistor tersebut dihubungkan ke GND Arduino. Resistor ini penting untuk melindungi LED dari arus berlebih.
Dengan konfigurasi ini, ketika modul relay diaktifkan oleh Arduino, sakelar internal relay akan menutup sirkuit antara pin COM dan NO, sehingga mengalirkan 5V ke LED dan membuatnya menyala.

Cara Kerja
Sensor Gas MQ: Membaca konsentrasi gas di lingkungan sekitar. Output analog (AO) sensor akan memberikan nilai yang bervariasi tergantung pada konsentrasi gas. Semakin tinggi konsentrasi gas berbahaya, semakin tinggi pula nilai analog yang dibaca.
Ambang Batas (Threshold): Ditetapkan dalam kode. Jika nilai analog dari sensor MQ melampaui ambang batas ini, sistem akan menginterpretasikannya sebagai deteksi gas berbahaya.
Logika Alarm & Aksi Relay:
Ketika konsentrasi gas terdeteksi melebihi ambang batas yang ditentukan, Arduino akan memicu kondisi "alarm".
Dalam kondisi alarm, Arduino akan:
Mengaktifkan buzzer untuk mengeluarkan pola suara peringatan (misalnya, 'bip-bip').
Mengirim sinyal ke modul relay untuk mengaktifkannya. Karena LED terhubung ke relay dalam konfigurasi COM ke 5V dan NO ke LED Anoda, LED akan menyala saat relay aktif.
Saat tidak ada bahaya, buzzer akan mati dan relay akan dinonaktifkan, sehingga LED juga akan mati.
Pemantauan: Status deteksi dan aksi akan dicetak ke Serial Monitor untuk debugging dan pemantauan.

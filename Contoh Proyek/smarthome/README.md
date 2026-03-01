Deskripsi Konsep Sistem Smart Home Arduino
🔧 1. Tujuan Sistem
Sistem ini dirancang untuk mengotomatiskan pengawasan lingkungan rumah dengan menggunakan sensor-sensor yang terintegrasi ke Arduino Uno. Setiap sensor memiliki fungsi spesifik yang memberikan respons langsung berupa perangkat output (seperti LED, relay, atau motor servo) ketika kondisi tertentu terdeteksi. Sistem ini juga menampilkan seluruh data sensor ke Serial Monitor sebagai bentuk monitoring digital.

---

🔌 2. Komponen Utama dan Fungsi
Komponen Fungsi

- Arduino Uno = Pusat kendali untuk membaca sensor dan mengatur output
- LDR (Light Dependent Resistor) = Mendeteksi intensitas cahaya lingkungan
- PIR Sensor = Mendeteksi gerakan manusia
- MQ-2 Gas Sensor= Mendeteksi konsentrasi gas berbahaya (misal: LPG, asap)
- DHT22 Sensor = Mengukur suhu dan kelembaban udara
- Relay Module = Mengaktifkan perangkat listrik (contoh: lampu, kipas, alarm)
- Servo Motor= Bergerak saat kondisi tertentu, misalnya untuk membuka pintu
- LED Merah Menyala saat ruangan gelap
- LED Kuning Menyala saat suhu tinggi (di atas 30°C)

---

🔁 3. Logika dan Cara Kerja Sistem

- Sensor Cahaya (LDR) → LED Merah
- LDR membaca intensitas cahaya.
- Jika nilai LDR rendah (gelap), maka LED Merah menyala.
- Sensor Gerak (PIR) → Relay
- Jika ada gerakan yang terdeteksi oleh sensor PIR, maka relay akan aktif.
- Relay bisa digunakan untuk menyalakan lampu otomatis atau sistem alarm.
- Sensor Gas (MQ-2) → Servo Motor

- Ketika konsentrasi gas berbahaya melebihi ambang batas (misalnya >400), servo bergerak ke sudut 90° (contoh: membuka ventilasi).

---

- Saat aman, servo kembali ke posisi awal (0°).
- Sensor Suhu dan Kelembaban (DHT22) → LED Kuning
- Jika suhu ruangan >30°C, LED kuning menyala sebagai peringatan.
- Jika suhu normal, LED mati.
- Serial Monitor

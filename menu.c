#include <stdio.h>   // Untuk fungsi input/output seperti printf, scanf
#include <stdlib.h>  // Untuk fungsi umum seperti exit
#include <time.h>    // Untuk fungsi waktu di modul util

// ====================================================================
// SECTION: Struct dan Deklarasi Fungsi (semua dari all_modules.h)
// ====================================================================

// Struktur untuk merepresentasikan opsi menu
typedef struct {
    char *label;        // Label menu (misal: "Registrasi Penyewa")
    void (*function)(); // Pointer ke fungsi yang akan dijalankan ketika opsi ini dipilih
    int required_role;  // Role yang dibutuhkan untuk mengakses menu ini (misal: 0=Guest, 1=User, 2=Admin)
} MenuItem;

// Deklarasi fungsi-fungsi menu
void display_main_menu(int user_role);
void handle_menu_selection(int choice, int user_role);

// Deklarasi fungsi-fungsi "wrapper" menu (yang akan dipanggil oleh pointer fungsi)
void menu_kamar_view_all();
void menu_kamar_add();
void menu_penyewa_registrasi();
void menu_penyewa_reservasi();
void menu_pembayaran_buat_faktur();
void menu_auth_login();
void menu_auth_logout();
void menu_auth_manage_accounts();
void menu_util_show_date();
void menu_exit_program();


// Deklarasi fungsi-fungsi modul Kamar
void init_kamar_module();
void view_all_kamar();
void add_kamar();


// Deklarasi fungsi-fungsi modul Penyewa
void init_penyewa_module();
void registrasi_penyewa();
void reservasi_penyewa();


// Deklarasi fungsi-fungsi modul Pembayaran
void init_pembayaran_module();
void buat_faktur();


// Deklarasi fungsi-fungsi modul Autentikasi
extern int current_logged_in_role; // Dideklarasikan extern di sini, didefinisikan di bagian implementasi

void init_auth_module();
int get_logged_in_user_role();
void user_login();
void user_logout();
void manage_user_accounts();


// Deklarasi fungsi-fungsi modul Utilitas
void init_util_module();
void show_current_date();


// Deklarasi fungsi inisialisasi semua modul (fungsi utama sebelum loop menu)
void init_modules();


// ====================================================================
// SECTION: Variabel Global
// ====================================================================
// Definisi variabel global dari modul autentikasi
int current_logged_in_role = 0; // 0: Guest, 1: User, 2: Admin


// ====================================================================
// SECTION: Implementasi Fungsi (semua dari all_modules.c)
// ====================================================================

// --- Implementasi Fungsi-fungsi "Wrapper" Menu ---
void menu_kamar_view_all() {
    printf("\n--- Menampilkan semua kamar ---\n");
    view_all_kamar();
}

void menu_kamar_add() {
    printf("\n--- Menambahkan kamar baru ---\n");
    add_kamar();
}

void menu_penyewa_registrasi() {
    printf("\n--- Registrasi Penyewa ---\n");
    registrasi_penyewa();
}

void menu_penyewa_reservasi() {
    printf("\n--- Reservasi Penyewa ---\n");
    reservasi_penyewa();
}

void menu_pembayaran_buat_faktur() {
    printf("\n--- Membuat Faktur Pembayaran ---\n");
    buat_faktur();
}

void menu_auth_login() {
    printf("\n--- Login Sistem ---\n");
    user_login();
}

void menu_auth_logout() {
    printf("\n--- Logout Sistem ---\n");
    user_logout();
}

void menu_auth_manage_accounts() {
    printf("\n--- Manajemen Akun User/Staff ---\n");
    manage_user_accounts();
}

void menu_util_show_date() {
    printf("\n--- Menampilkan Tanggal ---\n");
    show_current_date();
}

void menu_exit_program() {
    printf("Keluar dari program...\n");
    exit(0);
}

// Array untuk menyimpan item-item menu
MenuItem main_menu_items[] = {
    {"Login", menu_auth_login, 0},
    {"Lihat Semua Kamar", menu_kamar_view_all, 0},
    {"Registrasi Penyewa", menu_penyewa_registrasi, 0},
    {"Reservasi Kamar", menu_penyewa_reservasi, 1},
    {"Tambah Kamar", menu_kamar_add, 2},
    {"Buat Faktur Pembayaran", menu_pembayaran_buat_faktur, 1},
    {"Manajemen Akun User/Staff", menu_auth_manage_accounts, 2},
    {"Tampilkan Tanggal", menu_util_show_date, 0},
    {"Logout", menu_auth_logout, 1},
    {"Keluar", menu_exit_program, 0}
};

// Jumlah item dalam array menu
const int NUM_MAIN_MENU_ITEMS = sizeof(main_menu_items) / sizeof(MenuItem);

// Implementasi fungsi display_main_menu
void display_main_menu(int user_role) {
    printf("\n--- Menu Utama ---\n");
    for (int i = 0; i < NUM_MAIN_MENU_ITEMS; i++) {
        if (user_role >= main_menu_items[i].required_role) {
            printf("%d. %s\n", i + 1, main_menu_items[i].label);
        }
    }
    printf("------------------\n");
}

// Implementasi fungsi handle_menu_selection
void handle_menu_selection(int choice, int user_role) {
    if (choice > 0 && choice <= NUM_MAIN_MENU_ITEMS) {
        if (user_role >= main_menu_items[choice - 1].required_role) {
            main_menu_items[choice - 1].function();
        } else {
            printf("Anda tidak memiliki hak akses untuk opsi ini.\n");
        }
    } else if (choice == 0) {
        // Pilihan keluar, ditangani di loop main
    } else {
        printf("Pilihan tidak valid. Silakan coba lagi.\n");
    }
}


// --- Implementasi Fungsi-fungsi Modul Kamar ---
void init_kamar_module() {
    printf("[Kamar Module] diinisialisasi.\n");
}

void view_all_kamar() {
    printf("[Kamar Module] Fungsi: Melihat semua kamar\n");
    // TODO: Implementasi detail
}

void add_kamar() {
    printf("[Kamar Module] Fungsi: Menambahkan kamar baru\n");
    // TODO: Implementasi detail
}


// --- Implementasi Fungsi-fungsi Modul Penyewa ---
void init_penyewa_module() {
    printf("[Penyewa Module] diinisialisasi.\n");
}

void registrasi_penyewa() {
    printf("[Penyewa Module] Fungsi: Registrasi Penyewa\n");
    // TODO: Implementasi detail
}

void reservasi_penyewa() {
    printf("[Penyewa Module] Fungsi: Reservasi Penyewa\n");
    // TODO: Implementasi detail
}


// --- Implementasi Fungsi-fungsi Modul Pembayaran ---
void init_pembayaran_module() {
    printf("[Pembayaran Module] diinisialisasi.\n");
}

void buat_faktur() {
    printf("[Pembayaran Module] Fungsi: Membuat Faktur Pembayaran\n");
    // TODO: Implementasi detail
}


// --- Implementasi Fungsi-fungsi Modul Autentikasi ---
void init_auth_module() {
    printf("[Auth Module] diinisialisasi.\n");
}

int get_logged_in_user_role() {
    return current_logged_in_role;
}

void user_login() {
    printf("[Auth Module] Fungsi: Proses Login...\n");
    current_logged_in_role = 1;
    printf("[Auth Module] Login berhasil! Role Anda sekarang: User.\n");
}

void user_logout() {
    printf("[Auth Module] Fungsi: Proses Logout...\n");
    current_logged_in_role = 0;
    printf("[Auth Module] Anda telah logout.\n");
}

void manage_user_accounts() {
    printf("[Auth Module] Fungsi: Manajemen Akun User/Staff\n");
    // TODO: Implementasi detail
}


// --- Implementasi Fungsi-fungsi Modul Utilitas ---
void init_util_module() {
    printf("[Util Module] diinisialisasi.\n");
}

void show_current_date() {
    time_t t;
    time(&t);
    printf("[Util Module] Tanggal saat ini: %s", ctime(&t));
}


// --- Implementasi Fungsi Inisialisasi Utama ---
void init_modules() {
    printf("Memuat data awal dan menginisialisasi modul...\n");
    init_kamar_module();
    init_penyewa_module();
    init_pembayaran_module();
    init_auth_module();
    init_util_module();
    printf("Inisialisasi modul berhasil.\n");
}


// ====================================================================
// SECTION: Fungsi Utama (main)
// ====================================================================

int main() {
    init_modules(); // Inisialisasi semua modul

    int current_user_role = get_logged_in_user_role();
    int choice;

    do {
        display_main_menu(current_user_role);
        printf("Masukkan pilihan Anda: ");
        // Memastikan input adalah integer dan membersihkan buffer
        if (scanf("%d", &choice) != 1) {
            printf("Input tidak valid. Masukkan angka.\n");
            while (getchar() != '\n'); // Membersihkan sisa baris
            choice = -1; // Menetapkan nilai tidak valid untuk melanjutkan loop
        }
        while (getchar() != '\n'); // Pastikan buffer input kosong setelah membaca integer

        handle_menu_selection(choice, current_user_role);

    } while (choice != 0); // Loop berlanjut sampai pengguna memilih 0 (Keluar)

    printf("Terima kasih telah menggunakan aplikasi ini!\n");
    return 0;
}

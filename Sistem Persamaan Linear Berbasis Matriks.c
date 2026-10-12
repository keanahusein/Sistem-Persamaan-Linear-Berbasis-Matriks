#include <stdio.h>
#include <math.h>

void invers2x2() {
    double a, b, c, d, e, f, det, x, y;
    printf("\n--- SPLDV (Metode Invers 2x2) ---\n");
    printf("Bentuk: ax + by = e | cx + dy = f\n");
    printf("Masukkan a, b, e: ");
    scanf("%lf %lf %lf", &a, &b, &e);
    printf("Masukkan c, d, f: ");
    scanf("%lf %lf %lf", &c, &d, &f);

    det = a * d - b * c;
    if (det == 0) {
        printf("Sistem tidak memiliki solusi unik (det = 0).\n");
        return;
    }

    x = (d * e - b * f) / det;
    y = (-c * e + a * f) / det;

    printf("\nSolusi:\nx = %g\ny = %g\n", x, y);
}

void invers3x3() {
    int i, j;
    double A[3][3], B[3], det, adj[3][3], inv[3][3], X[3];
    printf("\n--- SPLTV (Metode Invers 3x3) ---\n");
    printf("Masukkan koefisien matriks A (3x3):\n");
    for (i = 0; i < 3; i++) {
        printf("Baris ke-%d (a, b, c): ", i + 1);
        scanf("%lf %lf %lf", &A[i][0], &A[i][1], &A[i][2]);
    }
    printf("Masukkan konstanta B (d1, d2, d3):\n");
    for (i = 0; i < 3; i++) {
        printf("d%d: ", i + 1);
        scanf("%lf", &B[i]);
    }

    det = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1])
        - A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0])
        + A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);

    if (det == 0) {
        printf("Sistem tidak memiliki solusi unik (det = 0).\n");
        return;
    }

    adj[0][0] =  (A[1][1] * A[2][2] - A[1][2] * A[2][1]);
    adj[0][1] = -(A[0][1] * A[2][2] - A[0][2] * A[2][1]);
    adj[0][2] =  (A[0][1] * A[1][2] - A[0][2] * A[1][1]);
    adj[1][0] = -(A[1][0] * A[2][2] - A[1][2] * A[2][0]);
    adj[1][1] =  (A[0][0] * A[2][2] - A[0][2] * A[2][0]);
    adj[1][2] = -(A[0][0] * A[1][2] - A[0][2] * A[1][0]);
    adj[2][0] =  (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
    adj[2][1] = -(A[0][0] * A[2][1] - A[0][1] * A[2][0]);
    adj[2][2] =  (A[0][0] * A[1][1] - A[0][1] * A[1][0]);

    for (i = 0; i < 3; i++) {
        X[i] = 0;
        for (j = 0; j < 3; j++) {
            inv[i][j] = adj[i][j] / det;
            X[i] += inv[i][j] * B[j];
        }
    }

    printf("\nSolusi:\nx = %g\ny = %g\nz = %g\n", X[0], X[1], X[2]);
}

void cramer2x2() {
    double a, b, c, d, e, f, D, Dx, Dy;
    printf("\n--- Aturan Cramer 2x2 ---\n");
    printf("Bentuk: ax + by = e | cx + dy = f\n");
    printf("Masukkan a, b, e: ");
    scanf("%lf %lf %lf", &a, &b, &e);
    printf("Masukkan c, d, f: ");
    scanf("%lf %lf %lf", &c, &d, &f);

    D  = a * d - b * c;
    Dx = e * d - b * f;
    Dy = a * f - e * c;

    if (D == 0) {
        printf("Sistem tidak memiliki solusi unik (D = 0).\n");
        return;
    }

    printf("\nSolusi:\nx = %g\ny = %g\n", Dx / D, Dy / D);
}

void cramer3x3() {
    int i;
    double A[3][3], B[3], D, Dx, Dy, Dz;
    printf("\n--- Aturan Cramer 3x3 ---\n");
    printf("Masukkan koefisien matriks A (3x3):\n");
    for (i = 0; i < 3; i++) {
        printf("Baris ke-%d (a, b, c): ", i + 1);
        scanf("%lf %lf %lf", &A[i][0], &A[i][1], &A[i][2]);
    }
    printf("Masukkan konstanta B (d1, d2, d3):\n");
    for (i = 0; i < 3; i++) {
        printf("d%d: ", i + 1);
        scanf("%lf", &B[i]);
    }

    D = A[0][0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1]) 
      - A[0][1]*(A[1][0]*A[2][2] - A[1][2]*A[2][0]) 
      + A[0][2]*(A[1][0]*A[2][1] - A[1][1]*A[2][0]);

    if (D == 0) {
        printf("Sistem tidak memiliki solusi unik (D = 0).\n");
        return;
    }

    Dx = B[0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1]) 
       - A[0][1]*(B[1]*A[2][2] - A[1][2]*B[2]) 
       + A[0][2]*(B[1]*A[2][1] - A[1][1]*B[2]);

    Dy = A[0][0]*(B[1]*A[2][2] - A[1][2]*B[2]) 
       - B[0]*(A[1][0]*A[2][2] - A[1][2]*A[2][0]) 
       + A[0][2]*(A[1][0]*B[2] - B[1]*A[2][0]);

    Dz = A[0][0]*(A[1][1]*B[2] - B[1]*A[2][1]) 
       - A[0][1]*(A[1][0]*B[2] - B[1]*A[2][0]) 
       + B[0]*(A[1][0]*A[2][1] - A[1][1]*A[2][0]);

    printf("\nSolusi:\nx = %g\ny = %g\nz = %g\n", Dx / D, Dy / D, Dz / D);
}

void gauss() {
    int n, i, j, k;
    double A[10][11], x[10], factor;
    printf("\n--- Eliminasi Gauss ---\n");
    printf("Masukkan jumlah variabel (maks 10): ");
    scanf("%d", &n);

    printf("Masukkan matriks augmented [A|B]:\n");
    for (i = 0; i < n; i++) {
        printf("Baris ke-%d: ", i + 1);
        for (j = 0; j <= n; j++) scanf("%lf", &A[i][j]);
    }

    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
            if (fabs(A[i][i]) < 1e-9) continue;
            factor = A[k][i] / A[i][i];
            for (j = i; j <= n; j++) A[k][j] -= factor * A[i][j];
        }
    }

    for (i = n - 1; i >= 0; i--) {
        x[i] = A[i][n];
        for (j = i + 1; j < n; j++) x[i] -= A[i][j] * x[j];
        if (fabs(A[i][i]) < 1e-9) {
            printf("Sistem tidak memiliki solusi unik.\n");
            return;
        }
        x[i] /= A[i][i];
    }

    printf("\nSolusi:\n");
    for (i = 0; i < n; i++) printf("x%d = %g\n", i + 1, x[i]);
}

void gaussJordan() {
    int n, i, j, k;
    double A[10][11], pivot, factor;
    printf("\n--- Eliminasi Gauss-Jordan ---\n");
    printf("Masukkan jumlah variabel (maks 10): ");
    scanf("%d", &n);

    printf("Masukkan matriks augmented [A|B]:\n");
    for (i = 0; i < n; i++) {
        printf("Baris ke-%d: ", i + 1);
        for (j = 0; j <= n; j++) scanf("%lf", &A[i][j]);
    }

    for (i = 0; i < n; i++) {
        pivot = A[i][i];
        if (fabs(pivot) < 1e-9) {
            printf("Sistem tidak memiliki solusi unik.\n");
            return;
        }
        for (j = i; j <= n; j++) A[i][j] /= pivot;
        for (k = 0; k < n; k++) {
            if (k != i) {
                factor = A[k][i];
                for (j = i; j <= n; j++) A[k][j] -= factor * A[i][j];
            }
        }
    }

    printf("\nSolusi:\n");
    for (i = 0; i < n; i++) printf("x%d = %g\n", i + 1, A[i][n]);
}

int main() {
    int pilihan;

    while (1) {
        printf("\n===========================================\n");
        printf("   PROGRAM PENYELESAIAN PERSAMAAN LINEAR   \n");
        printf("===========================================\n");
        printf("1. Metode Invers Matriks - SPLDV (2 Variabel)\n");
        printf("2. Metode Invers Matriks - SPLTV (3 Variabel)\n");
        printf("3. Metode Cramer - SPLDV (2 Variabel)\n");
        printf("4. Metode Cramer - SPLTV (3 Variabel)\n");
        printf("5. Metode Eliminasi Gauss\n");
        printf("6. Metode Eliminasi Gauss-Jordan\n");
        printf("0. Keluar\n");
        printf("-------------------------------------------\n");
        printf("Pilih menu (0-6): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: invers2x2(); break;
            case 2: invers3x3(); break;
            case 3: cramer2x2(); break;
            case 4: cramer3x3(); break;
            case 5: gauss(); break;
            case 6: gaussJordan(); break;
            case 0: 
                printf("\nTerima kasih! Program selesai.\n");
                return 0;
            default: 
                printf("\nPilihan tidak valid! Coba lagi.\n");
        }
    }

    return 0;
}

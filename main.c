#include<stdio.h>
#include <memory.h>
#include <string.h>
#include <struct.h>

typedef struct sinhvien {
    char maSV[50];
    char ten[50];
    char sdt[50];
} SINHVIEN;

SINHVIEN mangSV[10];
int i = 0;

void removeStdChar(char array[]) {
    if (strchr(array, '\n') == NULL) {
        while (fgetc(stdin) != '\n');
    }
}

nhapMoi() {
    int done = 0;
    int thoat;

    do {
        printf("\nẤn 1 để tiếp tục , ấn 0 để quay lại menu: ");
        scanf("%d", &thoat);
        getchar();
        if (thoat == 0) {
            done = 1;
        } else if (thoat != 1 && thoat != 0) {
        } else {
            do {
                printf("\nNhập mã sinh viên (gồm 05 ký tự): ");
                fgets(mangSV[i].maSV, sizeof(mangSV[i].maSV) * sizeof(char), stdin);
                removeStdChar(mangSV[i].maSV);
            } while (strlen(mangSV[i].maSV) != 6);

            printf("\nNhập tên sinh viên: ");
            fgets(mangSV[i].ten, sizeof(mangSV[i].ten) * sizeof(char), stdin);
            removeStdChar(mangSV[i].ten);

            printf("\nNhập số điện thoại: ");
            fgets(mangSV[i].sdt, sizeof(mangSV[i].sdt) * sizeof(char), stdin);
            removeStdChar(mangSV[i].sdt);
            i++;
        }
    } while (!done && i < 10);
    if (done) {
    } else
        printf("\nDanh sách sinh viên đã đầy.\n");
}

hienThi() {
    int j = 0;
    printf("\n------------------ DANH SÁCH SINH VIÊN ------------------");
    printf("\n");
    printf("\n+------+-------+--------------------------+-------------+");
    printf("\n|  STT | MÃ SV |            TÊN           |    SDT      |");
    printf("\n+------+-------+--------------------------+-------------+");
    for (int j = 0; j < i; j++) {
        printf("\n| %3d  | ", j + 1);
        mangSV[j].maSV[strlen(mangSV[j].maSV) - 1] = ' ';
        mangSV[j].ten[strlen(mangSV[j].ten) - 1] = ' ';
        mangSV[j].sdt[strlen(mangSV[j].sdt) - 1] = ' ';
        printf("%-5s| %-25s| %-12s|", mangSV[j].maSV, mangSV[j].ten, mangSV[j].sdt);
    }
    printf("\n+------+-------+--------------------------+-------------+");
}

luuRaFile() {
    int k;
    FILE *fp;
    fp = fopen("../danhsachsinhvien.txt", "w");
    fprintf(fp, "\n------------------ DANH SÁCH SINH VIÊN ------------------");
    fprintf(fp, "\n");
    fprintf(fp, "\n+------+-------+--------------------------+-------------+");
    fprintf(fp, "\n|  STT | MÃ SV |            TÊN           |    SDT      |");
    fprintf(fp, "\n+------+-------+--------------------------+-------------+");
    for (int k = 0; k < i; k++) {
        fprintf(fp, "\n| %3d  | ", k + 1);
        mangSV[k].maSV[strlen(mangSV[k].maSV) - 1] = ' ';
        mangSV[k].ten[strlen(mangSV[k].ten) - 1] = ' ';
        mangSV[k].sdt[strlen(mangSV[k].sdt) - 1] = ' ';
        fprintf(fp, "%-5s| %-25s| %-12s|", mangSV[k].maSV, mangSV[k].ten, mangSV[k].sdt);
    }
    fprintf(fp, "\n+------+-------+--------------------------+-------------+");
        fclose(fp);
}

docTuFile(){
    FILE *fp;
    fp = fopen("../danhsachsinhvien.txt", "r");
    while (fgets(mangSV, 10, fp) != NULL) {
        printf("%s", mangSV);
    }
}

taoMenu() {
    while (1) {
        int luaChon;
        printf("\n-------------- Menu --------------\n");
        printf("1. Thêm mới sinh viên.\n");
        printf("2. Hiển thị danh sách sinh viên.\n");
        printf("3. Lưu danh sách sinh viên ra file.\n");
        printf("4. Đọc danh sách sinh viên từ file.\n");
        printf("5. Thoát chương trình.\n");
        printf("----------------------------------\n");
        printf("Lựa chọn của bạn là: ");
        scanf("%d", &luaChon);
        getchar();
        if (luaChon == 5) {
            printf("\nBạn đã thoát chương trình. Hẹn gặp lại!\n");
            break;
        }
        switch (luaChon) {
            case 1:
                nhapMoi();
                break;
            case 2:
                hienThi();
                break;
            case 3:
                printf("Danh sách sinh viên đã được lưu ra file danhsachsinhvien.txt\n");
                luuRaFile();
                break;
            case 4:
                docTuFile();
                break;
            default:
                printf("\nVui lòng ấn số từ 1 đến 5.\n");
                break;
        }
    }
}

void main() {
    taoMenu();
}


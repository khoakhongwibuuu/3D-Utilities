#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

const double PI = 3.141592653589793;

struct Point
{
    double x;
    double y;
};

bool nearly_approx(double A, double B)
{
    double delta = A - B;
    if (delta < 0)
        delta *= -1;

    return (delta < 1e-4f);
}

int pytago_checker(double AB, double AC, double BC)
{
    const double A = AB * AB;
    const double B = AC * AC;
    const double C = BC * BC;
    if (nearly_approx(A + B, C))
        return 0;
    else if (A + B < C)
        return 2;
    else
        return 1;
}

double radianToDegree(double angle)
{
    double newangle = (angle * 180 / PI);
    if (newangle > 90 && !nearly_approx(newangle, 90))
        newangle -= 90;
    return newangle;
}

double khoang_cach_hai_diem(struct Point A, struct Point B)
{
    double deltaX = A.x - B.x;
    double deltaY = A.y - B.y;
    return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
}

double goc_o_dinh(int idx, double AB, double AC, double BC)
{
    const double AB_2 = AB * AB;
    const double AC_2 = AC * AC;
    const double BC_2 = BC * BC;

    if (idx == 0)
    {
        double cosA = (BC_2 - AB_2 - AC_2) / (-2 * AB * AC);
        double angleA_inRadian = acos(cosA);
        double angleA_inDeg = radianToDegree(angleA_inRadian);

        int triangle_type = pytago_checker(AB, AC, BC);
        if (triangle_type == 2)
            return angleA_inDeg + 90;
        else
            return angleA_inDeg;
    }
    else if (idx == 1)
    {
        double cosB = (AC_2 - AB_2 - BC_2) / (-2 * AB * BC);
        double angleB_inRadian = acos(cosB);
        double angleB_inDeg = radianToDegree(angleB_inRadian);

        int triangle_type = pytago_checker(AB, BC, AC);
        if (triangle_type == 2)
            return angleB_inDeg + 90;
        else
            return angleB_inDeg;
    }
    else
    {
        double cosC = (AB_2 - BC_2 - AC_2) / (-2 * BC * AC);
        double angleC_inRadian = acos(cosC);
        double angleC_inDeg = radianToDegree(angleC_inRadian);

        int triangle_type = pytago_checker(BC, AC, AB);
        if (triangle_type == 2)
            return angleC_inDeg + 90;
        else
            return angleC_inDeg;
    }
}

bool kiemtra_tamgiac(struct Point A, struct Point B, struct Point C)
{
    double AB = khoang_cach_hai_diem(A, B);
    double AC = khoang_cach_hai_diem(A, C);
    double BC = khoang_cach_hai_diem(C, B);
    return (AB + BC > AC) && (AB + AC > BC) && (BC + AC > AB);
}

void goccanh_tamgiac(double AB, double AC, double BC)
{
    printf("Do dai doan AB: %0.2f\n", AB);
    printf("Do dai doan AC: %0.2f\n", AC);
    printf("Do dai doan BC: %0.2f\n", BC);
    double angleA = goc_o_dinh(0, AB, AC, BC);
    double angleB = goc_o_dinh(1, AB, AC, BC);
    double angleC = goc_o_dinh(2, AB, AC, BC);
    printf("Goc o dinh A: %0.2f\n", angleA);
    printf("Goc o dinh B: %0.2f\n", angleB);
    printf("Goc o dinh C: %0.2f\n", angleC);
}

int xet_tamgiac(double AB, double AC, double BC)
{
    if (nearly_approx(AB, AC) && nearly_approx(AB, BC))
        return 0;
    else
    {

        if (nearly_approx(AB, AC))
            return 10 + pytago_checker(AB, AC, BC);

        else if (nearly_approx(AB, BC))
            return 20 + pytago_checker(AB, BC, AC);

        else if (nearly_approx(AC, BC))
            return 30 + pytago_checker(AC, BC, AB);

        else
        {
            const int Point_A_status = pytago_checker(AB, AC, BC);

            if (Point_A_status % 2 == 0)
                return 40 + Point_A_status;

            else
            {
                const int Point_B_status = pytago_checker(AB, BC, AC);

                if (Point_B_status % 2 == 0)
                    return 50 + Point_B_status;

                else
                {
                    const int Point_C_status = pytago_checker(AC, BC, AB);

                    if (Point_C_status % 2 == 0)
                        return 60 + Point_C_status;

                    else
                        return 1;
                }
            }
        }
    }
}

double dientich_tamgiac(double AB, double AC, double BC)
{

    const double p = (AB + AC + BC) * 0.5f;
    return (double)(sqrt(p * (p - AB) * (p - AC) * (p - BC)));
}

double duongcao_tamgiac(int idx, double AB, double AC, double BC, double area)
{
    if (idx == 0)
        return (double)area * 2 / BC;
    else if (idx == 1)
        return (double)area * 2 / AC;
    else
        return (double)area * 2 / AB;
}

double trungtuyen_tamgiac(int idx, double AB, double AC, double BC)
{
    const double AB_2 = AB * AB;
    const double AC_2 = AC * AC;
    const double BC_2 = BC * BC;
    if (idx == 0)
    {
        const double mA_2 = (2 * (AC_2 + AB_2) - BC_2) / 4;
        return (double)sqrt(mA_2);
    }
    else if (idx == 1)
    {
        const double mB_2 = (2 * (BC_2 + AB_2) - AC_2) / 4;
        return (double)sqrt(mB_2);
    }
    else
    {
        const double mC_2 = (2 * (BC_2 + AC_2) - AB_2) / 4;
        return (double)sqrt(mC_2);
    }
}

void tam_tamgiac(struct Point A, struct Point B, struct Point C)
{
    const double X = (A.x + B.x + C.x) / 3;
    const double Y = (A.y + B.y + C.y) / 3;
    printf("--------------------------------------\n4. Toa do trong tam tam giac ABC la G(%0.2f, %0.2f)\n\n", X, Y);
}

void giaima_tamgiac(struct Point A, struct Point B, struct Point C)
{

    if (kiemtra_tamgiac(A, B, C))
    {
        printf("--------------------------------------\n3 diem da cho CO the tao thanh tam giac\n\n");
        const double AB = khoang_cach_hai_diem(A, B);
        const double AC = khoang_cach_hai_diem(A, C);
        const double BC = khoang_cach_hai_diem(C, B);
        printf("--------------------------------------\n1. So do co ban cua tam giac\n");
        goccanh_tamgiac(AB, AC, BC);

        switch (xet_tamgiac(AB, AC, BC))
        {
        case 1:
            printf("Tam giac ABC la tam giac binh thuong");
            break;
        case 0:
            printf("Tam giac ABC la tam giac deu");
            break;
        case 10:
            printf("Tam giac ABC la tam giac vuong can tai A");
            break;
        case 11:
            printf("Tam giac ABC la tam giac can tai A");
            break;
        case 12:
            printf("Tam giac ABC la tam giac tu va can tai A");
            break;
        case 20:
            printf("Tam giac ABC la tam giac vuong can tai B");
            break;
        case 21:
            printf("Tam giac ABC la tam giac can tai B");
            break;
        case 22:
            printf("Tam giac ABC la tam giac tu va can tai B");
            break;
        case 30:
            printf("Tam giac ABC la tam giac vuong can tai C");
            break;
        case 31:
            printf("Tam giac ABC la tam giac can tai C");
            break;
        case 32:
            printf("Tam giac ABC la tam giac tu va can tai C");
            break;
        case 40:
            printf("Tam giac ABC la tam giac vuong tai A");
            break;
        case 42:
            printf("Tam giac ABC la tam giac tu tai A");
            break;
        case 50:
            printf("Tam giac ABC la tam giac vuong tai B");
            break;
        case 52:
            printf("Tam giac ABC la tam giac tu tai B");
            break;
        case 60:
            printf("Tam giac ABC la tam giac vuong tai C");
            break;
        case 62:
            printf("Tam giac ABC la tam giac tu tai C");
            break;
        }
        printf("\n\n");

        const double area = dientich_tamgiac(AB, AC, BC);
        printf("--------------------------------------\n2. Dien tich tam giac ABC: %0.2f\n\n", area);
        printf("--------------------------------------\n3. So do nang cao tam giac ABC:\n");
        printf("Chieu dai duong cao tu dinh A: %0.2f\n", duongcao_tamgiac(0, AB, AC, BC, area));
        printf("Chieu dai duong cao tu dinh B: %0.2f\n", duongcao_tamgiac(1, AB, AC, BC, area));
        printf("Chieu dai duong cao tu dinh C: %0.2f\n", duongcao_tamgiac(2, AB, AC, BC, area));
        printf("Chieu dai duong trung tuyen tu dinh A: %0.2f\n", trungtuyen_tamgiac(0, AB, AC, BC));
        printf("Chieu dai duong trung tuyen tu dinh B: %0.2f\n", trungtuyen_tamgiac(1, AB, AC, BC));
        printf("Chieu dai duong trung tuyen tu dinh C: %0.2f\n", trungtuyen_tamgiac(2, AB, AC, BC));
        printf("\n");
        tam_tamgiac(A, B, C);
    }
    else
        printf("Ba diem da cho KHONG the tao thanh tam giac");
}

int main()
{
    struct Point PointArray[3];
    char PointLabel[] = {'A', 'B', 'C'};

    for (int i = 0; i < 3; i++)
    {
        printf("Nhap toa do diem %c:\n", PointLabel[i]);
        printf("%c.x: ", PointLabel[i]);
        scanf("%lf", &PointArray[i].x);
        printf("%c.y: ", PointLabel[i]);
        scanf("%lf", &PointArray[i].y);
        printf("Toa do diem %c la %c(%0.2f, %0.2f)\n\n", PointLabel[i], PointLabel[i], PointArray[i].x, PointArray[i].y);
    }
    giaima_tamgiac(PointArray[0], PointArray[1], PointArray[2]);
    return 0;
}

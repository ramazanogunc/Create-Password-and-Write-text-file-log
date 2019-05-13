#include <stdio.h>
#include <time.h>

int CreatePassword();
void Filewrite( char *isim, char *password );

int main()
{
    srand(time(NULL));
    int basamakSayisi, i;
    char isim[100];
    printf( "Sifre ismi (Ornegin github sifresi " );
    gets( isim );
    printf( "Kac basamak sifre uretmek istersiniz:" );
    scanf( "%d", &basamakSayisi );

    if ( basamakSayisi <=0 )
    {
        printf( "!! HATA 0 veya negatif bir bir basamak sayisi girdiniz sayi bu basamak  sifre uretilemez. " );
        return 0;
    }

    char password[basamakSayisi];

    for (i = 0; i < basamakSayisi ; i++)
    {
        printf("buraya giriyor musun \n");
        password[i] = CreatePassword();
        if( password[i - 1] == password[i] )
            password[i] = CreatePassword();
    }
    Filewrite( isim, password );
    printf( "\nSifreniz uretilmis ve dosyaya yazmistir.\n" );
    printf( "%s -> %s", isim, password );

    return 0;
}

int CreatePassword()
{
    return 35 + rand()%125;
}

void Filewrite( char *isim, char *password )
{
    FILE *fp = fopen("Sifreler.txt","a");
    fprintf( fp, "%s -> %s\n", isim, password);
    fclose(fp);
}

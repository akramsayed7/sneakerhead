#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
char RegisteredUsername[50];
char RegisteredPassword[50];
char username[50];
char password[50];
int logged_in = 0;
int amount = 0, Totalamount = 0;
int count = 0, Shoe = 0;
int size;

static char Username[50];
struct ShoeOrder {
    char name[100];
    int amount;
};

struct ShoeOrder orders[100];
int orderCount = 0;

void Register();
bool Login();
void CategoriesOfShoes();
void CasualSneakers();
void RunningShoes();
void TrainingShoes();
void LeatherBoots();
void Loafers();
void Type(char* bName);
void ShoeType(char* type, char* bName);
void Casnewbtype();
void Storage();
void BillAmount();
void CasBNikeType(char* type);
void CasAdidasType(char* type);
void CasPUmaType(char* type);
int SelectSize();
void RunNike();
void RunAdidas();
void RunPuma();
void trainNike();
void TrainAdidas();
void TrainPuma();
void feedback();




int main() {
    printf("\033[5;35m\t#######################################################################################################\033[0m\n");
    printf("\033[5;35m\t#                                                                                                     #\033[0m\n");
    printf("\033[5;35m\t#   **********************************************************************************************    #\033[0m\n");
    printf("\033[5;35m\t#  *                                                                                              *   #\033[0m\n");
    printf("\033[5;35m\t#  *    \033[5;33m  \t............REGISTER AND BECOME A SNEAKERHEAD........... \033[0m \033[5;35m                        *   #\033[0m\n");
    printf("\033[5;35m\t#  *                                                                                              *   #\033[0m\n");
    printf("\033[5;35m\t#  *                                                                                              *   #\033[0m\n");
    printf("\033[5;35m\t#  *                                                                                              *   #\033[0m\n");
    printf("\033[5;35m\t#  * \033[5;33m       NEW BALANCE    NIKE    ADIDAS ORIGINALS    PUMA      CONVERSE \033[0m \033[5;35m                       *   #\033[0m\n");
    printf("\033[5;35m\t#  *                                                                                              *   #\033[0m\n");
    printf("\033[5;35m\t#   **********************************************************************************************    #\033[0m\n");
    printf("\033[5;35m\t#                                                                                                     #\033[0m\n");
    printf("\033[5;35m\t#######################################################################################################\033[0m\n");
    printf("\n");

    int opt;
    while (1) {
        printf("\n1. Register\n2. Login\n3. Exit\n");
        printf("Enter the option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                Register();
                break;
            case 2:
                if (Login()) {
                    CategoriesOfShoes();
                } else {
                    printf("Invalid username or password.\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void takepassword(char password[20])
{
    int i=0;
    char ch;
    while(1)
    {
        ch = getch();
        if(ch==13){
            password[i]='\0';
            break;
        }
        else if(ch==8)
        {
            if(i>0)
            {
                i--;
                printf("\b\b");
            }
        }
        else if(ch==9||ch==32){
            continue;
        }
        else{
            password[i++]=ch;
            printf("*");
        }
    }
    printf("\n");
}

void Register() {
    printf("Enter Username: ");
    scanf("%s", RegisteredUsername);
    printf("Enter Password: ");
    takepassword(RegisteredPassword);
    printf("\n");
    printf("\033[33m------------------------------------------------Registered successfully-------------------------------------------------\033[0m\n");

    FILE *file = fopen("Register.csv", "a");
    if (file == NULL) {
        perror("Could not open file");
        exit(1);
    }

    fprintf(file, "%s,%s\n", RegisteredUsername, RegisteredPassword);
    fclose(file);
}


bool Login() {
    printf("Enter Registered Username: ");
    scanf("%s", username);

    printf("Enter Registered Password: ");
    takepassword(password);

    FILE *file = fopen("Register.csv", "r");
    if (file == NULL) {
        printf("Could not open file");
        exit(1);
    }

    char file_username[50];
    char file_password[50];
    while (fscanf(file, "%[^,],%s\n", file_username, file_password) != EOF) {
        if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0) {
            logged_in = 1;
            break;
        }
    }
    fclose(file);

    if (logged_in) {
        printf("Login successful!\n");
        return 1;
    } else {

        printf("Invalid username or password.\n");
    }
}

void CategoriesOfShoes() {
    int opt;
    printf("\033[33m---------------------------------------------------Select shoe Category--------------------------------------------------------\033[0m\n1. Casual Sneakers\n2. Running Shoes\n3. Training Shoes\n4. Loafers\n5. Leather Boots \n");
    printf("Enter the option: ");
    scanf("%d", &opt);
    switch (opt) {
        case 1:
            CasualSneakers();
            break;
        case 2:
            RunningShoes();
            break;
        case 3:
            TrainingShoes();
            break;
        case 4:
            Loafers();
            break;
        case 5:
            LeatherBoots();
            break;
        default:
            printf("Invalid option. Please try again.\n");
            CategoriesOfShoes();
    }
}

void CasualSneakers() {
    int opt;
    printf("\033[33m---------------------------------------------------Select Brand----------------------------------------------------------\033[0m\n1. Nike\n2. Adidas\n3. Puma\n4. New balance\n");
    printf("Enter the option: ");
    scanf("%d", &opt);
    switch (opt) {
        case 1:
            Type("Nike");
            break;
        case 2:
            Type("Adidas");
            break;
        case 3:
            Type("Puma");
            break;
        case 4:
             Casnewbtype();
            break;
        default:
            printf("Invalid option. Please try again.\n");
            CasualSneakers();
    }
}

void Type(char* bName) {
    int opt;
    printf("\033[33m----------------------------------------------------Select Ordering-----------------------------------------------------------\033[0m\n1. Lowtop Casual Sneakers\n2. Midtop Casual Sneakers\n3. Hightop Casual Sneakers\n");
    printf("Enter the option: ");
    scanf("%d", &opt);
    switch (opt) {
        case 1:
            ShoeType("low", bName);
            break;
        case 2:
            ShoeType("mid", bName);
            break;
        case 3:
            ShoeType("high", bName);
            break;
        default:
            printf("Invalid option. Please try again.\n");
            Type("Nike");
            return;
    }
}

void ShoeType(char* type, char* bName) {
    if (strcmp(bName, "Nike") == 0)
        {
        CasBNikeType(type);
        }
    else if (strcmp(bName, "Adidas") == 0)
    {
        CasAdidasType(type);
    }
    else
    {
        CasPUmaType(type);
    }
}

void CasBNikeType(char* type)
{
    int opt;
    if (strcmp(type, "low") == 0) {
        printf("\033[33m--------------------------------------------------------Select Ordering--------------------------------------------------------\033[0m\n1. Nike Panda Dunks\n2. Nike Air Force\n3. Travis Scott x Air Jordan 1 Low OG Olive\n");
    }
    else if (strcmp(type, "mid") == 0)
    {
        printf("\033[33m--------------------------------------------------------Select Ordering--------------------------------------------------------\033[0m\n1. Nike Men Ebron Mid\n2. Nike Men Blazer Mid 77 Vintage\n3. Air Jordan 1 Mid\n");
    }
    else
        {
        printf("\033[33m--------------------------------------------------------Select Ordering--------------------------------------------------------\033[0m\n1. Air Jordan 6 Retro\n2. Air Jordan 1 Retro High OG Lost and Found\n3. Air Jordan 1 High OG Spider Man\n");
    }
    printf("Enter the option: ");
    scanf("%d", &opt);
    switch (opt)
     {
        case 1:
            if (strcmp(type, "low") == 0)
             {
                printf("Nike Panda Dunks\n");
                amount = 8945;
                strcpy(orders[orderCount].name, "Nike Panda Dunks");
            }
    else if (strcmp(type, "mid") == 0)
        {
                printf("Nike Men Ebron Mid\n");
                amount = 5995;
                strcpy(orders[orderCount].name, "Nike Men Ebron Mid");
            }
    else
        {
                printf("Air Jordan 6 Retro\n");
                amount = 18395;
                strcpy(orders[orderCount].name, "Air Jordan 6 Retro");
            }
            break;
        case 2:
            if (strcmp(type, "low") == 0)
            {
                printf("Nike Air Force\n");
                amount = 9695;
                strcpy(orders[orderCount].name, "Nike Air Force");
            }
    else if (strcmp(type, "mid") == 0)
        {
                printf("Nike Men Blazer Mid 77 Vintage\n");
                amount = 7995;
                strcpy(orders[orderCount].name, "Nike Men Blazer Mid 77 Vintage");
            }
    else
        {
                printf("Air Jordan 1 Retro High OG Lost and Found\n");
                amount = 37999;
                strcpy(orders[orderCount].name, "Air Jordan 1 Retro High OG Lost and Found");
            }
            break;
        case 3:
            if (strcmp(type, "low") == 0)
            {
                printf("Travis Scott x Air Jordan 1 Low OG Olive\n");
                amount = 110000;
                strcpy(orders[orderCount].name, "Travis Scott x Air Jordan 1 Low OG Olive");
            }
    else if (strcmp(type, "mid") == 0)
        {
                printf("Air Jordan 1 Mid\n");
                amount = 11495;
                strcpy(orders[orderCount].name, "Air Jordan 1 Mid");
            }
    else {
                printf("Air Jordan 1 High OG Spider Man\n");
                amount = 25000;
                strcpy(orders[orderCount].name, "Air Jordan 1 High OG Spider Man");
            }
            break;
        default:
            printf("Invalid option. Please try again.\n");
            CasBNikeType(type);
            return;
    }
    orders[orderCount].amount = amount;
    orderCount++;
    SelectSize();
}

void CasAdidasType(char* type)
 {
    int opt;
    if (strcmp(type, "low") == 0)
        {
        printf("\033[33m--------------------------------------------------------Select Ordering--------------------------------------------------------\033[0m\n1. Samba OG Sneakers\n2. Superstar XLG\n3. Adifom Sneakers\n");
    }
    else if (strcmp(type, "mid") == 0)
        {
        printf("\033[33m--------------------------------------------------------Select Ordering--------------------------------------------------------\033[0m\n1. Adidas Men Forum Mid Sneakers\n2. Adidas Men Hoops Mid 3.0 Sneakers\n3. Adidas Postmove Casual Sneakers\n");
    }
    else
        {
        printf("\033[33m--------------------------------------------------------Select Ordering--------------------------------------------------------\033[0m\n1. Adidas Forum 84 Sneakers\n2. Adidas Rivalry Hightop Sneakers\n3. Adidas Striped Nubuck Sneakers\n");
    }
    printf("Enter the option: ");
    scanf("%d", &opt);
    switch (opt)
    {
        case 1:
            if (strcmp(type,"low")==0)
            {
                printf("Samba OG Sneakers\n");
                amount = 8999;
                strcpy(orders[orderCount].name, "Samba OG Sneakers");
            }
    else if (strcmp(type,"mid")==0)
        {
                printf("Adidas Men Forum Mid Sneakers\n");
                amount = 6499;
                strcpy(orders[orderCount].name, "Adidas Men Forum Mid Sneakers");
            } else
            {
                printf("Adidas Forum 84 Sneakers\n");
                amount = 7799;
                strcpy(orders[orderCount].name, "Adidas Forum 84 Sneakers");
            }
            break;
        case 2:
            if (strcmp(type, "low") == 0)
            {
                printf("Superstar XLG\n");
                amount = 7799;
                strcpy(orders[orderCount].name, "Superstar XLG");
            }
    else if (strcmp(type, "mid") == 0)
        {
                printf("Adidas Men Hoops Mid 3.0 Sneakers\n");
                amount = 4549;
                strcpy(orders[orderCount].name, "Adidas Men Hoops Mid 3.0 Sneakers");
            }
    else {
                printf("Adidas Rivalry Hightop Sneakers\n");
                amount = 6719;
                strcpy(orders[orderCount].name, "Adidas Rivalry Hightop Sneakers");
            }
            break;
        case 3:
            if (strcmp(type, "low") == 0)
                {
                printf("Adifom Sneakers\n");
                amount = 8399;
                strcpy(orders[orderCount].name, "Adifom Sneakers");
            }
            else if (strcmp(type, "mid") == 0)
                {
                printf("Adidas Postmove Casual Sneakers\n");
                amount = 9695;
                strcpy(orders[orderCount].name, "Adidas Postmove Casual Sneakers");
            }
            else
                {
                printf("Adidas Striped Nubuck Sneakers\n");
                amount = 6999;
                strcpy(orders[orderCount].name, "Adidas Striped Nubuck Sneakers");
            }
            break;
           default:
            printf("Invalid option. Please try again.\n");
            return;
    }
    orders[orderCount].amount = amount;
    orderCount++;
    SelectSize();
}

void CasPUmaType(char* type)
 {
    int opt;
    if (strcmp(type, "low") == 0)
        {
        printf("\033[33m--------------------------------------------------------Select Ordering--------------------------------------------------------\033[0m\n1. Puma Men Fire V2 Sneakers\n2. Puma Men Coloured Blocked Sneakers\n3. Puma Men Lite Pro Sneakers\n");
    }
    else if (strcmp(type, "mid") == 0)
        {
        printf("\033[33m--------------------------------------------------------Select Ordering--------------------------------------------------------\033[0m\n1. Puma Caven 2.0 Mid Unisex Sneakers\n2. One8 x Puma Men Smash Sneakers\n3. Puma Evoke Layup Mid Sneakers\n");
    }
    else
        {
        printf("\033[33m--------------------------------------------------------Select Ordering--------------------------------------------------------\033[0m\n1. Puma BMW M Motorsport A3ROCAT Sneakers\n2. Puma Slipstream Hi Heritage Hightop Sneakers\n3. Puma 1949 Unisex Sneakers\n");
    }
    printf("Enter the option: ");
    scanf("%d", &opt);
    switch (opt)
    {
        case 1:
            if (strcmp(type, "low") == 0)
            {
                printf("Puma Men Fire V2 Sneakers\n");
                amount = 2149;
                strcpy(orders[orderCount].name, "Puma Men Fire V2 Sneakers");
            }
    else if (strcmp(type, "mid") == 0)
        {
                printf("Puma Caven 2.0 Mid Unisex Sneakers\n");
                amount = 3849;
                strcpy(orders[orderCount].name, "Puma Caven 2.0 Mid Unisex Sneakers");
            }
    else {
                printf("Puma BMW M Motorsport A3ROCAT Sneakers\n");
                amount = 5499;
                strcpy(orders[orderCount].name, "Puma BMW M Motorsport A3ROCAT Sneakers");
            }
            break;
        case 2:
            if (strcmp(type, "low") == 0)
                {
                printf("Puma Men Coloured Blocked Sneakers\n");
                amount = 1799;
                strcpy(orders[orderCount].name, "Puma Men Coloured Blocked Sneakers");
            }
            else if (strcmp(type, "mid") == 0)
                {
                printf("One8 x Puma Men Smash Sneakers\n");
                amount = 3749;
                strcpy(orders[orderCount].name, "One8 x Puma Men Smash Sneakers");
            }
            else
                {
                printf("Puma Slipstream Hi Heritage Hightop Sneakers\n");
                amount = 6999;
                strcpy(orders[orderCount].name, "Puma Slipstream Hi Heritage Hightop Sneakers");
            }
            break;
        case 3:
            if (strcmp(type, "low") == 0)
                {
                printf("Puma Men Lite Pro Sneakers\n");
                amount = 8945;
                strcpy(orders[orderCount].name, "Puma Men Lite Pro Sneakers");
            }
            else if (strcmp(type, "mid") == 0)
                {
                printf("Puma Evoke Layup Mid Sneakers\n");
                amount = 4499;
                strcpy(orders[orderCount].name, "Puma Evoke Layup Mid Sneakers");
            }
            else
                {
                printf("Puma 1949 Unisex Sneakers\n");
                amount = 2799;
                strcpy(orders[orderCount].name, "Puma 1949 Unisex Sneakers");
            }
            break;

        default:
            printf("Invalid option. Please try again.\n");
            return;

    }
     orders[orderCount].amount = amount;
    orderCount++;
    SelectSize();
}
void Casnewbtype()
    {
     printf("\033[33m----------------------------------------------------------Select Ordering--------------------------------------------------------\033[0m\n1. New balance 9060 men Sneakers\n2. New balance 327 men Sneakers\n3. New balance 996 men Sneakers\n4. New balance XC72 men Sneakers \n5. New balance 650 high top men Sneakers\n");

    int opt;
    printf("Enter the option: ");
    scanf("%d", &opt);
    switch (opt) {
        case 1:
            {
                printf("New balance 9060 men Sneakers\n");
                amount = 19639;
                strcpy(orders[orderCount].name, "New balance 9060 men Sneakers");
            }
            break;
        case 2:
            {
                printf("New balance 327 men Sneakers\n");
                amount = 8799;
                strcpy(orders[orderCount].name, "New balance 327 men Sneakers");
            }
            break;
        case 3:
            {
                printf("New balance 996 men Sneakers\n");
                amount = 9147;
                strcpy(orders[orderCount].name, "New balance 996 men Sneakers");
            }
            break;
      case 4:
            {
                printf("New balance XC72 men Sneakers\n");
                amount = 9099;
                strcpy(orders[orderCount].name, "New balance XC72 men Sneakers");
            }
            break;
        case 5:
            {
                printf("New balance 650 high top men Sneakers\n");
                amount =14399;
                strcpy(orders[orderCount].name, "New balance 650 high top men Sneakers");
            }
            break;


        default:
            printf("Invalid option. Please try again.\n");
            return;
    }
    orders[orderCount].amount = amount;
    orderCount++;
    SelectSize();
}

void RunningShoes() {
    int opt;
    printf("\033[33m--------------------------------------------------------Select Brand----------------------------------------------------------------\033[0m\n1. Nike\n2. Adidas\n3. Puma\n");
    printf("Enter the option: ");
    scanf("%d", &opt);
    switch (opt)
    {
        case 1:
            RunNike();
            break;
        case 2:
            RunAdidas();
            break;
        case 3:
            RunPuma();
            break;
       default:
            printf("Invalid option. Please try again.\n");
            RunningShoes();
            return;
    }
}
void RunNike()
{

    printf("\033[33m--------------------------------------------------------Select Ordering--------------------------------------------------------\033[0m\n1. nike v2k running shoe\n2. nike men flex 12 running shoes \n3. nike pegasus running shoes \n");

    int opt;
    printf("Enter the option: ");
    scanf("%d", &opt);
    switch (opt)
     {
        case 1:
            {
                printf("nike v2k running shoe\n");
                amount = 7556;
                strcpy(orders[orderCount].name, "nike v2k running shoe");
            }
            break;
        case 2:
            {
                printf("nike men flex 12 running shoes\n");
                amount = 3496;
                strcpy(orders[orderCount].name, "nike men flex 12 running shoes");
            }
            break;
        case 3:
            {
                printf("nike pegasus running shoes\n");
                amount = 8046;
                strcpy(orders[orderCount].name, "nike pegasus running shoes");
            }
            break;
            default:
            printf("Invalid option. Please try again.\n");
            RunNike();
            return;
    }
    orders[orderCount].amount = amount;
    orderCount++;
    SelectSize();
}
void RunAdidas()

{
    printf("\033[33m---------------------------------------------------------Select Ordering--------------------------------------------------------\033[0m\n1. Adidas vac-run running shoe\n2. Adidas men zapcore running shoes \n3. Adidas glide stride running shoes \n");
   int opt;
    printf("Enter the option: ");
    scanf("%d", &opt);
    switch (opt)
    {
        case 1:
            {
                printf("Adidas vac-run running shoe\n");
                amount = 2759;
                strcpy(orders[orderCount].name, "Adidas vac-run running shoe");
            }
            break;
        case 2:
            {
                printf("Adidas men zapcore running shoes\n");
                amount = 2255;
                strcpy(orders[orderCount].name, "Adidas men zapcore running shoes");
            }
            break;
        case 3:
            {
                printf("Adidas glide stride running shoes\n");
                amount = 2349;
                strcpy(orders[orderCount].name, "Adidas glide stride running shoes");
            }
            break;
            default:
            printf("Invalid option. Please try again.\n");
            RunAdidas();
            return;
    }
    orders[orderCount].amount = amount;
    orderCount++;
    SelectSize();
}
void RunPuma()
{
    printf("\033[33m----------------------------------------------------------Select Ordering----------------------------------------------------------\033[0m\n1. puma fierce running shoe\n2. puma fusion x running shoes \n3. puma ultragrip running shoes \n");

    int opt;
    printf("Enter the option: ");
    scanf("%d", &opt);
    switch (opt)
    {
        case 1:
            {
                printf("puma fierce running shoe\n");
                amount = 2477;
                strcpy(orders[orderCount].name, "puma fierce running shoe");
            }
            break;
        case 2:
            {
                printf("puma fusion x running shoes\n");
                amount = 2199;
                strcpy(orders[orderCount].name, "puma fusion x running shoes");
            }
            break;
        case 3:
            {
                printf("puma ultragrip running shoes \n");
                amount = 2399;
                strcpy(orders[orderCount].name, "puma ultragrip running shoes ");
            }
            break;
            default:
            printf("Invalid option. Please try again.\n");
            RunPuma();
            return;
    }
    orders[orderCount].amount = amount;
    orderCount++;
    SelectSize();
}
void TrainingShoes()
{
    int opt;
    printf("\033[33m----------------------------------------------------------Select Brand------------------------------------------------------------\033[0m\n1. Nike\n2. Adidas\n3. Puma\n");
    printf("Enter the option: ");
    scanf("%d", &opt);
    switch (opt) {
        case 1:
            trainNike();
            break;
        case 2:
            trainAdidas();
            break;
        case 3:
            trainPuma();
            break;
       default:
            printf("Invalid option. Please try again.\n");
            TrainingShoes();
            return;
    }
}

void trainNike()
{
    printf("\033[33m--------------------------------------------------------Select Ordering--------------------------------------------------------\033[0m\n1. Nike AM alpha t5 training shoe\n2. Nike MC trainer 3 training shoes \n3. Nike bella 6 training shoes \n");

    int opt;
    printf("Enter the option: ");
    scanf("%d", &opt);
    switch (opt)
     {
        case 1:
            {
                printf("Nike AM alpha t5 training shoe\n");
                amount = 7495;
                strcpy(orders[orderCount].name, "Nike AM alpha t5 training shoe");
            }
            break;
        case 2:
            {
                printf("Nike MC trainer 3 training shoes\n");
                amount = 5695;
                strcpy(orders[orderCount].name, "Nike MC trainer 3 training shoes");
            }
            break;
        case 3:
            {
                printf("Nike bella 6 training shoes \n");
                amount = 2769;
                strcpy(orders[orderCount].name, "Nike bella 6 training shoes ");
            }
            break;
            default:
            printf("Invalid option. Please try again.\n");
            trainNike();
            return;
    }
    orders[orderCount].amount = amount;
    orderCount++;
    SelectSize();
}

void trainAdidas()
{
printf("\033[33m--------------------------------------------------------Select Ordering--------------------------------------------------------\033[0m\n1. Adidas new star indoor training shoe\n2. Adidas ligra 7M training shoes \n3. Adidas acer indoor training shoes \n");

    int opt;
    printf("Enter the option: ");
    scanf("%d", &opt);
    switch (opt)
    {
        case 1:
            {
                printf("Adidas new star indoor training shoe\n");
                amount = 3119;
                strcpy(orders[orderCount].name, "Adidas new star indoor training shoe");
            }
            break;
        case 2:
            {
                printf("Adidas ligra 7M training shoes\n");
                amount = 3419;
                strcpy(orders[orderCount].name, "Adidas ligra 7M training shoes");
            }
            break;
        case 3:
            {
                printf("Adidas acer indoor training shoes\n");
                amount = 2749;
                strcpy(orders[orderCount].name, "Adidas acer indoor training shoes");
            }
            break;
            default:
            printf("Invalid option. Please try again.\n");
            trainAdidas();
            return;
    }
    orders[orderCount].amount = amount;
    orderCount++;
    SelectSize();
}

void trainPuma()
{
 printf("\033[33m--------------------------------------------------------Select Ordering--------------------------------------------------------\033[0m\n1. puma infusion training shoes\n2. puma remedie training shoes \n3. puma prospect training shoes \n");

    int opt;
    printf("Enter the option: ");
    scanf("%d", &opt);
    switch (opt)
    {
        case 1:
            {
                printf("puma infusion training shoes\n");
                amount = 3849;
                strcpy(orders[orderCount].name, "puma infusion training shoes");
            }
            break;
        case 2:
            {
                printf("puma remedie training shoes\n");
                amount = 3249;
                strcpy(orders[orderCount].name, "puma remedie training shoes");
            }
            break;
        case 3:
            {
                printf("puma prospect training shoes \n");
                amount = 3899;
                strcpy(orders[orderCount].name, "puma prospect training shoes ");
            }
            break;
            default:
            printf("Invalid option. Please try again.\n");
            trainPuma();
            return;
    }
    orders[orderCount].amount = amount;
    orderCount++;
    SelectSize();
}
void Loafers()
{
 printf("\033[33m--------------------------------------------------------Select Ordering--------------------------------------------------------\033[0m\n1.BALLY-paklys leather loofers \n2. TOD'S- T timeless gommino bubble loafers \n3.TOD'S-double T leather loafers  \n4.FERRAGAMO- drivers leather loafers with gancini ornament  \n");

    int opt;
    printf("Enter the option: ");
    scanf("%d", &opt);
    switch (opt)
    {
        case 1:
            {
                printf("BALLY-paklys leather loofers\n");
                amount = 45500;
                strcpy(orders[orderCount].name, "BALLY-paklys u leather loofers");
            }
            break;
        case 2:
            {
                printf("TOD'S- T timeless gommino bubble loafers\n");
                amount = 65000;
                strcpy(orders[orderCount].name, "TOD'S- T timeless gommino bubble loafers");
            }
            break;
        case 3:
            {
                printf("TOD'S-double T leather loafres \n");
                amount = 56000;
                strcpy(orders[orderCount].name, "TOD'S-double T leather loafers  ");
            }
            break;
        case 4:
            {
                printf("FERRAGAMO-drivers leather loafers with gancini ornament \n");
                amount = 63000;
                strcpy(orders[orderCount].name, "FERRAGAMO-drivers leather loafers with gancini ornament  ");
            }
            break;
            default:
            printf("Invalid option. Please try again.\n");
            Loafers();
            return;
    }
    orders[orderCount].amount = amount;
    orderCount++;
    SelectSize();
}

void LeatherBoots()
   {
 printf("\033[33m--------------------------------------------------------Select Ordering--------------------------------------------------------\033[0m\n1.LEE COOPER-laceup boots \n2.ECCO-ankle length boots \n3.GEOX-Dwalk pleasure ankle length boots \n4.BALLY- scavone leather boots \n5.RAWLS-colourblock slip-on chelsea boots \n");

    int opt;
    printf("Enter the option: ");
    scanf("%d", &opt);
    switch (opt)
    {
        case 1:
            {
                printf("LEE COOPER-laceup boots\n");
                amount = 1650;
                strcpy(orders[orderCount].name, "LEE COOPER-laceup boots");
            }
            break;
        case 2:
            {
                printf("ECCO-ankle length boots \n");
                amount = 15999;
                strcpy(orders[orderCount].name, "ECCO-ankle length boots ");
            }
            break;
        case 3:
            {
                printf("GEOX-Dwalk pleasure ankle length boots\n");
                amount = 6495;
                strcpy(orders[orderCount].name, "GEOX-Dwalk pleasure ankle length boots");
            }
            break;
            case 4:
            {
                printf("BALLY- scavone leather boots");
                amount = 84000;
                strcpy(orders[orderCount].name, "BALLY- scavone leather boots");
            }
            break;
            case 5:
            {
                printf("GEOX-Dwalk pleasure ankle length boots\n");
                amount = 6495;
                strcpy(orders[orderCount].name, "RAWLS-colourblock slip-on chelsea boots ");
            }
            break;
            default:
            printf("Invalid option. Please try again.\n");
            LeatherBoots();
            return;
    }
    orders[orderCount].amount = amount;
    orderCount++;
    SelectSize();
}



int SelectSize()
{
    printf("\nSelect Size:\n6\n7\n8\n9\n");
    printf("\nEnter the size: ");
    scanf("%d", &size);

    if (size >= 6 && size <= 9) {
        printf("Size %d selected.\n", size);
        BillAmount();
    } else {
        printf("Invalid size. Please select a valid size.\n");
        SelectSize();
    }

    return size;
}

void BillAmount()
{
    Totalamount += amount;

    printf("\n\033[31m===========================================>>Current Order Details<<===============================================================\033[0m\n\n");
    for (int i = 0; i < orderCount; i++)
        {
        printf("%d. %s - %d\n", i + 1, orders[i].name, orders[i].amount);
    }
    printf("Total amount: %d\n\n", Totalamount);
    Storage();

    char s;
    printf("If you want to select another category again, enter y; otherwise, enter n to proceed to billing.\n\n");
    scanf(" %c",&s);
    if (s =='y')
        {
        CategoriesOfShoes();
    }
    else {
        printf("Final total amount: %d\n\n", Totalamount);
        printf("\033[31m=================================================>>>order placed successfully<<<=====================================================\033[0m\n");
         printf("\033[33m=================================================>>>Please give your feedback<<<=====================================================\033[0m\n");
        feedback();
        exit(0);
    }
}

void Storage()
{
    FILE *pointer=fopen("Orders.csv","a");
    if (pointer==NULL)
        {
        perror("Could not open file");
        exit(1);
    }

    for (int i=0;i<orderCount;i++)
        {
        fprintf(pointer,"%s,%s,%d,%d\n",username,orders[i].name,size,orders[i].amount);
    }
    fclose(pointer);
}

void feedback() {
    int rating;
    printf("Please rate your experience (1-5): \n");
    scanf("%d", &rating);
    switch (rating) {
        case 1:
            printf("We're sorry to hear that. We will strive to improve.\n");
            break;
        case 2:
            printf("We appreciate your feedback. We'll work on it.\n");
            break;
        case 3:
            printf("Thank you for your feedback. We will aim to do better.\n");
            break;
        case 4:
            printf("Thank you! We're glad you had a good experience.\n");
            break;
        case 5:
            printf("Excellent! We're thrilled you had a great experience.\n");
            break;
        default:
            printf("Invalid rating. Please provide a rating between 1 and 5.\n");
            feedback();
            return;
    }
    printf("Thank you for shopping with us!\n");
}

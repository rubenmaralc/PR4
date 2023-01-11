#include <iostream>
#include <time.h>
#include <Windows.h>
#include <mmstream.h>
#include <stdlib.h>

using namespace std;

//hero
string heroName;//se consulta al usuario
int heroHP = 9999;
bool heroAlive = true;
string heroAbility1 = "Atacar";
int damageAbility1 = 250;
string heroAbility2 = "Electro";
int damageAbility2 = 500;
string heroAbility3 = "Aqua";
int damageAbility3 = 750;
string heroAbility4 = "Piro";
int damageAbility4 = 2500;
int accountAbility4 = 2;
string heroAbility5 = "DevastacionPlanetaria";//Límite Estelar: Solo cuando te quedan 1000 HP.
int damageAbility5 = 9999;
string heroChoose;
string heroAbilityChoose;
string heroSpeak;

//enemy1
string enemy1Name = "Adamantaimai";
int enemy1HP = 3000;
//int enemy1Damage = rand() % 1200 + 500;
bool enemy1Alive = true;
string enemy1Ability = "Tormenta de agua";


//enemy2
string enemy2Name = "Dragon";
int enemy2HP = 5000;
//int enemy2Damage = rand() % 1600 + 800;
bool enemy2Alive = true;
string enemy2Ability = "Aliento TetraElemental";

//funciones
void startGame() {
    //bool soundIntro = PlaySound(TEXT("Intro.wav"), NULL, SND_ASYNC);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 23);

    cout << "************************************************************************************************************************\n";
    cout << "************************************************************************************************************************\n";
    cout << "**********                            ____   ____                 _______                                     **********\n";
    cout << "**********                           |  __| | ___|               |______ |                                    **********\n";
    cout << "**********                           | |_   | |_    ______             / /                                    **********\n";
    cout << "**********                           |  _|  |  _|  |______|           / /                                     **********\n";
    cout << "**********                           | |    | |                      / /                                      **********\n";
    cout << "**********                           |_|    |_|                     /_/                                       **********\n";
    cout << "**********                                                                                                    **********\n";
    cout << "************************************************************************************************************************\n";
    cout << "************************************************************************************************************************\n";
    cout << endl;
    cout << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "Hola? Hoooooola? Tsss Tsss.... despierta. Como te llamas?\n";
    cin >> heroName;
    cout << "Encantada de conocerte " << heroName << ". Me llamo Limukta y soy la diosa encargada del planeta en el cual te acabas de despertar.\nComo te encuentras?\n";
    cin >> heroSpeak;
    cout << "Bueno... no se si alegrarme de que estes " << heroSpeak << ".\nSi estas aqui, es por un motivo. Mi planeta esta al borde de la destruccion y necesitamos tu ayuda\n";
    cout << "Se que vienes de GAIA. Por lo menos aqui en el planeta LEONIS lo conocemos por ese nombre. Has sido elegido para salvar nuestro planeta.\nEspero no haberte importunado, pero no me queda otra eleccion si quiero que LEONIS sobreviva.\n";
    cout << "Mientras hablamos los dragones estan destruyendo todo a su paso y vienen de camino. Si la situacion continua asi.... Me temo lo peor.\nPor favor... necesito tu ayuda!\n";
    cout << "Te parece bien?\n";
    cin >> heroSpeak;
    cout << "Aunque te parezca bien o no, el destino te ha traido aqui por algo. Hay algo especial en ti.\nEn tu interior existe una fuerza superior a cualquier otra que exista en el universo.\n";
    cout << "Oh no! Ahi estan! Tienes que luchar con ellos si o si, vamos?\n";
    cin >> heroSpeak;
    cout << endl;
    if (heroSpeak == "No" || heroSpeak == "no" || heroSpeak == "NO")
    {
        cout << "De verdad " << heroName << "?\n ";
        cout << "La verdad que esperaba mucho mas de ti. Con esta actitud voy a tener que enfrentar yo misma a los dragones.\nNo me sirves de nada.\n";
        cout << "Preparate para recibir el castigo de la diosa!\n";
        //bool soundAlert = PlaySound(TEXT("godattack.wav"), NULL, SND_SYNC);
        cout << "Limukta ha utilizado DON DIVINO contra ti.\n";
        heroAlive = false;
    }
    else
    {
        //bool soundAlert = PlaySound(TEXT("Alerta.wav"), NULL, SND_SYNC);
        cout << "Si no consigues derrotar a estos monstruos sera el fin de este planeta.\n" << heroName << " esta es la prueba final. TE NECESITAMOS!\n";
    }
}
void final() {
    //bool soundVictory = PlaySound(TEXT("Victory.wav"), NULL, SND_SYNC);
    //bool soundFinal1 = PlaySound(TEXT("Final1.wav"), NULL, SND_ASYNC);
    cout << endl;
    cout << heroName << "! Lo has conseguido! El planeta LEONIS podra tener un futuro gracias a ti. Ahora puedes volver a GAIA. \nEspero que volvamos a vernos pronto.\n";
    cout << "Y espero que sea en mejores condiciones.\n";
    cout << "Espero que hayas podido disfrutar de tus nuevos poderes y los uses correctamente a partir de ahora. Supongo que querras volver a tu hogar, no?\n";
    cin >> heroSpeak;
    cout << endl;
    //bool soundAlert2 = PlaySound(TEXT("Alerta.wav"), NULL, SND_SYNC);
    //bool soundFinal2 = PlaySound(TEXT("Final2.wav"), NULL, SND_ASYNC);
    cout << "No puede ser.... " << heroName << ", GAIA esta en peligro! El jefe de los Dragones, KARYOU, ha enviado a un ejercito a tu planeta.\n";
    cout << "Tienes que volver de inmediato " << heroName << "! Y yo... ire contigo en este viaje. Se que mis poderes pueden ser utiles para salvar GAIA." << endl << endl << endl;
    cout << "CONTINUARA....." << endl << endl;

    cout << "Opinion del jugador\nTe ha gustado " << heroName << "?\nSi\nNo\n";
    cin >> heroSpeak;
    cout << endl;
    if (heroSpeak == "Si" || heroSpeak == "si")
    {
        cout << "Me alegro muchisimo que hayas disfrutado jugando.\nHasta la proxima!";
        cout << endl;
    }
    else {
        cout << "Vaya...me sabe mal!\nEspero recibir feedback para poder mejorar en el futuro.\nMuchas gracias!";
        cout << endl;
    }
}
void gameOver() {
    cout << endl;
    cout << "Te quedan 0 puntos de vida.\n";
    //bool soundDeath = PlaySound(TEXT("HeroDeath.wav"), NULL, SND_SYNC);
    cout << "El planeta Leonis morira porque no fuiste capaz de derrotar a tus enemigos." << endl << endl << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "GAME OVER\n" << endl << endl << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void attack(int& damage, int& hp) {
    hp = hp - damage;
}
bool status(int& HP) {
    if (HP > 0)
    {
        return true;
    }
    else if (HP <= 0)
    {
        return false;
    }
}
void abilityChoose(string& enemyName) {
    cout << "Que habilidad quieres utilizar contra " << enemyName << "?\n";
    cout << heroAbility1 << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << heroAbility2 << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    cout << heroAbility3 << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << heroAbility4 << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cin >> heroAbilityChoose;
    cout << endl;
}
void abilityUse(string& heroAbility, string& enemyName) {
    cout << "Has utilizado " << heroAbility << " contra " << enemyName << "\n";
}
void enemyHP(string& enemyName, int enemyHP) {
    cout << "Al enemigo " << enemyName << " le quedan " << enemyHP << " puntos de vida.\n";
}
void enemyAbilityUse() {
    if (enemy1Alive && enemy2Alive)
    {
        cout << "El enemigo " << enemy1Name << " ha utilizado " << enemy1Ability << ".\nEl enemigo " << enemy2Name << " ha utilizado " << enemy2Ability << ".\n";
    }
    else if (enemy1Alive && enemy2Alive == false)
    {
        cout << "El enemigo " << enemy1Name << " ha utilizado " << enemy1Ability << " .\n";
    }
    else if (enemy2Alive && enemy1Alive == false)
    {
        cout << "El enemigo " << enemy2Name << " ha utilizado " << enemy2Ability << " .\n";
    }

}
void enemyChoose() {
    if (enemy1Alive && enemy2Alive)
    {
        cout << "Escoge a que enemigo quieres atacar?: " << enemy1Name << " o " << enemy2Name << "\n";
        cin >> heroChoose;
        cout << endl;
    }
    else if (enemy1Alive && enemy2Alive == false)
    {
        cout << "Vamos " << heroName << "! Solamente queda eliminar a " << enemy1Name << "!\nSelecciona a tu enemigo para atacarlo: " << enemy1Name << "\n";
        cin >> heroChoose;
        cout << endl;
    }
    else if (enemy2Alive && enemy1Alive == false)
    {
        cout << "Vamos " << heroName << "! Solamente queda eliminar a " << enemy2Name << "!\nSelecciona a tu enemigo para atacarlo: " << enemy2Name << "\n";
        cin >> heroChoose;
        cout << endl;
    }
}
void enemyDie(string& enemyName) {
    cout << "Has matado a " << enemyName << "\n";
}

int main()
{
    srand(time(NULL));
    int enemy1Damage = rand() % 1200 + 500;
    int enemy2Damage = rand() % 1600 + 800;

    startGame();

    while (heroAlive && (enemy1Alive || enemy2Alive))
    {
        //bool soundAbility5 = PlaySound(TEXT("Battle.wav"), NULL, SND_ASYNC);
        if (heroHP > 0 && heroHP <= 1000)
        {
            heroAlive = status(heroHP);
            //bool soundAbility5 = PlaySound(TEXT("Ability5.wav"), NULL, SND_ASYNC);
            cout << "Oh no! Estas al limite de tus fuerzas.\nUn aura brillante empieza a salir de tu interior.\nHas despertado tu limite estelar. Vamos a usarlo!\n";
            cout << "Escoge tu limite estelar!\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
            cout << "DevastacionPlanetaria\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            cin >> heroAbilityChoose;
            cout << endl;
            cout << "Has utilizado tu limite estelar " << heroAbility5 << " contra tus enemigos. \n SAYONARA BABY!\n";
            attack(damageAbility5, enemy1HP);
            attack(damageAbility5, enemy2HP);
            cout << "Los enemigos se esfuman ante tu tecnica especial.\n";
            enemy1Alive = status(enemy1HP);
            enemy2Alive = status(enemy2HP);
        }
        else if (heroAlive && enemy1Alive && enemy2Alive)
        {
            enemyChoose();
            if (heroChoose == enemy1Name)
            {
                abilityChoose(enemy1Name);
                if (heroAbilityChoose == heroAbility1)
                {
                    abilityUse(heroAbility1, enemy1Name);
                    attack(damageAbility1, enemy1HP);
                    if (enemy1HP > 0)
                    {
                        enemyHP(enemy1Name, enemy1HP);
                        enemy1Alive = status(enemy1HP);
                        enemy2Alive = status(enemy2HP);
                        attack(enemy1Damage, heroHP);
                        attack(enemy2Damage, heroHP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                    else {
                        enemyDie(enemy1Name);
                        attack(enemy2Damage, heroHP);
                        enemy1Alive = status(enemy1HP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                }
                else if (heroAbilityChoose == heroAbility2)
                {
                    abilityUse(heroAbility2, enemy1Name);
                    attack(damageAbility2, enemy1HP);
                    if (enemy1HP > 0)
                    {
                        enemyHP(enemy1Name, enemy1HP);
                        enemy1Alive = status(enemy1HP);
                        enemy2Alive = status(enemy2HP);
                        attack(enemy1Damage, heroHP);
                        attack(enemy2Damage, heroHP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                    else {
                        enemyDie(enemy1Name);
                        attack(enemy2Damage, heroHP);
                        enemy1Alive = status(enemy1HP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                }
                else if (heroAbilityChoose == heroAbility3)
                {
                    abilityUse(heroAbility3, enemy1Name);
                    attack(damageAbility3, enemy1HP);
                    if (enemy1HP > 0)
                    {
                        enemyHP(enemy1Name, enemy1HP);
                        enemy1Alive = status(enemy1HP);
                        enemy2Alive = status(enemy2HP);
                        attack(enemy1Damage, heroHP);
                        attack(enemy2Damage, heroHP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                    else {
                        enemyDie(enemy1Name);
                        attack(enemy2Damage, heroHP);
                        enemy1Alive = status(enemy1HP);
                        enemyAbilityUse();

                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                }
                else if (heroAbilityChoose == heroAbility4)
                {
                    accountAbility4 = accountAbility4 - 1;
                    if (accountAbility4 >= 0)
                    {
                        abilityUse(heroAbility4, enemy1Name);
                        attack(damageAbility4, enemy1HP);
                    }
                    else
                    {
                        cout << "Tu nivel actual no permite utilizar mas veces esta habilidad.\n";
                    }

                    if (enemy1HP > 0)
                    {
                        enemyHP(enemy1Name, enemy1HP);
                        enemy1Alive = status(enemy1HP);
                        enemy2Alive = status(enemy2HP);
                        attack(enemy1Damage, heroHP);
                        attack(enemy2Damage, heroHP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                    else {
                        enemyDie(enemy1Name);
                        attack(enemy2Damage, heroHP);
                        enemy1Alive = status(enemy1HP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                }
                else {
                    cout << "Que haces " << heroName << "? Debes escoger una habilidad para poder salvar el planeta.\nPrueba otra vez.";
                }
            }
            else if (heroChoose == enemy2Name)
            {
                abilityChoose(enemy2Name);
                if (heroAbilityChoose == heroAbility1)
                {
                    abilityUse(heroAbility1, enemy2Name);
                    attack(damageAbility1, enemy2HP);
                    if (enemy2HP > 0)
                    {
                        enemy1Alive = status(enemy1HP);
                        enemy2Alive = status(enemy2HP);
                        enemyHP(enemy2Name, enemy2HP);
                        attack(enemy1Damage, heroHP);
                        attack(enemy2Damage, heroHP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                    else {
                        enemyDie(enemy2Name);
                        attack(enemy1Damage, heroHP);
                        enemy2Alive = status(enemy2HP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                }
                else if (heroAbilityChoose == heroAbility2)
                {
                    abilityUse(heroAbility2, enemy2Name);
                    attack(damageAbility2, enemy2HP);
                    if (enemy2HP > 0)
                    {
                        enemyHP(enemy2Name, enemy2HP);
                        enemy1Alive = status(enemy1HP);
                        enemy2Alive = status(enemy2HP);
                        attack(enemy1Damage, heroHP);
                        attack(enemy2Damage, heroHP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                    else {
                        enemyDie(enemy2Name);
                        attack(enemy1Damage, heroHP);
                        enemy2Alive = status(enemy2HP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                }
                else if (heroAbilityChoose == heroAbility3)
                {
                    abilityUse(heroAbility3, enemy2Name);
                    attack(damageAbility3, enemy2HP);
                    if (enemy2HP > 0)
                    {
                        enemyHP(enemy2Name, enemy2HP);
                        enemy1Alive = status(enemy1HP);
                        enemy2Alive = status(enemy2HP);
                        attack(enemy1Damage, heroHP);
                        attack(enemy2Damage, heroHP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                    else {
                        enemyDie(enemy2Name);
                        attack(enemy1Damage, heroHP);
                        enemy2Alive = status(enemy2HP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                }
                else if (heroAbilityChoose == heroAbility4)
                {
                    accountAbility4 = accountAbility4 - 1;
                    if (accountAbility4 >= 0)
                    {
                        abilityUse(heroAbility4, enemy2Name);
                        attack(damageAbility4, enemy2HP);
                    }
                    else
                    {
                        cout << "Tu nivel actual no permite utilizar mas veces esta habilidad.\n";
                    }
                    if (enemy2HP > 0)
                    {
                        enemyHP(enemy2Name, enemy2HP);
                        enemy1Alive = status(enemy1HP);
                        enemy2Alive = status(enemy2HP);
                        attack(enemy1Damage, heroHP);
                        attack(enemy2Damage, heroHP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                    else {
                        enemyDie(enemy2Name);
                        attack(enemy1Damage, heroHP);
                        enemy2Alive = status(enemy2HP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                }
                else {
                    cout << "Que haces " << heroName << "? Debes escoger una habilidad para salvar el planeta.\nPrueba otra vez.";
                }
            }
            else {
                cout << "Que haces " << heroName << "? Debes escoger a un enemigo para salvar el planeta.\nPrueba otra vez.";
            }
        }
        else if (heroAlive && enemy1Alive)
        {
            enemyChoose();
            if (heroChoose == enemy1Name)
            {
                abilityChoose(enemy1Name);
                if (heroAbilityChoose == heroAbility1)
                {
                    abilityUse(heroAbility1, enemy1Name);
                    attack(damageAbility1, enemy1HP);
                    if (enemy1HP > 0)
                    {
                        enemy1Alive = status(enemy1HP);
                        enemyHP(enemy1Name, enemy1HP);
                        attack(enemy1Damage, heroHP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                    else {
                        enemyDie(enemy1Name);
                        enemy1Alive = status(enemy1HP);
                    }
                }
                else if (heroAbilityChoose == heroAbility2)
                {
                    abilityUse(heroAbility2, enemy1Name);
                    attack(damageAbility2, enemy1HP);
                    if (enemy1HP > 0)
                    {
                        enemy1Alive = status(enemy1HP);
                        enemyHP(enemy1Name, enemy1HP);
                        attack(enemy1Damage, heroHP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                    else {
                        enemyDie(enemy1Name);
                        enemy1Alive = status(enemy1HP);
                    }
                }
                else if (heroAbilityChoose == heroAbility3)
                {
                    abilityUse(heroAbility3, enemy1Name);
                    attack(damageAbility3, enemy1HP);
                    if (enemy1HP > 0)
                    {
                        enemy1Alive = status(enemy1HP);
                        enemyHP(enemy1Name, enemy1HP);
                        attack(enemy1Damage, heroHP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                    else {
                        enemyDie(enemy1Name);
                        enemy1Alive = status(enemy1HP);
                    }
                }
                else if (heroAbilityChoose == heroAbility4)
                {
                    accountAbility4 = accountAbility4 - 1;
                    if (accountAbility4 >= 0)
                    {
                        abilityUse(heroAbility4, enemy1Name);
                        attack(damageAbility4, enemy1HP);
                    }
                    else
                    {
                        cout << "Tu nivel actual no permite utilizar mas veces esta habilidad.\n";
                    }

                    if (enemy1HP > 0)
                    {
                        enemy1Alive = status(enemy1HP);
                        enemyHP(enemy1Name, enemy1HP);
                        attack(enemy1Damage, heroHP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                    else {
                        enemyDie(enemy1Name);
                        enemy1Alive = status(enemy1HP);
                    }
                }
            }
            else {
                cout << "Que haces " << heroName << "? Debes escoger a un enemigo para salvar el planeta.\nPrueba otra vez.";
            }
        }
        else if (heroAlive && enemy2Alive)
        {
            enemyChoose();
            if (heroChoose == enemy2Name)
            {
                abilityChoose(enemy2Name);
                if (heroAbilityChoose == heroAbility1)
                {
                    abilityUse(heroAbility1, enemy2Name);
                    attack(damageAbility1, enemy2HP);
                    if (enemy2HP > 0)
                    {
                        enemy2Alive = status(enemy2HP);
                        enemyHP(enemy2Name, enemy2HP);
                        attack(enemy2Damage, heroHP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                    else {
                        enemyDie(enemy2Name);
                        enemy2Alive = status(enemy2HP);
                    }
                }
                else if (heroAbilityChoose == heroAbility2)
                {
                    abilityUse(heroAbility2, enemy2Name);
                    attack(damageAbility2, enemy2HP);
                    if (enemy2HP > 0)
                    {
                        enemy2Alive = status(enemy2HP);
                        enemyHP(enemy2Name, enemy2HP);
                        attack(enemy2Damage, heroHP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                    else {
                        enemyDie(enemy2Name);
                        enemy2Alive = status(enemy2HP);
                    }
                }
                else if (heroAbilityChoose == heroAbility3)
                {
                    abilityUse(heroAbility3, enemy2Name);
                    attack(damageAbility3, enemy2HP);
                    if (enemy2HP > 0)
                    {
                        enemy2Alive = status(enemy2HP);
                        enemyHP(enemy2Name, enemy2HP);
                        attack(enemy2Damage, heroHP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                    else {
                        enemyDie(enemy2Name);
                        enemy2Alive = status(enemy2HP);
                    }
                }
                else if (heroAbilityChoose == heroAbility4)
                {
                    accountAbility4 = accountAbility4 - 1;
                    if (accountAbility4 >= 0)
                    {
                        abilityUse(heroAbility4, enemy2Name);
                        attack(damageAbility4, enemy2HP);
                    }
                    else
                    {
                        cout << "Tu nivel actual no permite utilizar mas veces esta habilidad.\n";
                    }
                    if (enemy2HP > 0)
                    {
                        enemy2Alive = status(enemy2HP);
                        enemyHP(enemy2Name, enemy2HP);
                        attack(enemy2Damage, heroHP);
                        enemyAbilityUse();
                        if (heroHP > 0)
                        {
                            cout << "Te quedan " << heroHP << " puntos de vida.\n";
                        }
                        else {
                            heroAlive = status(heroHP);
                        }
                    }
                    else {
                        enemyDie(enemy2Name);
                        enemy2Alive = status(enemy2HP);
                    }
                }
                else {
                    cout << "Que haces " << heroName << "? Debes escoger una habilidad para poder salvar el planeta.\nPrueba otra vez.";
                }
            }
            else {
                cout << "Que haces " << heroName << "? Debes escoger a un enemigo para salvar el planeta.\nPrueba otra vez.";
            }
        }
    }
    if (heroAlive)
    {
        final();
    }
    else {
        gameOver();
    }


}

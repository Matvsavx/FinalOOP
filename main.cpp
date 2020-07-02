#include <iostream>
#include <vector>

using namespace std;

class FightManager {
    bool isWin;
    bool isDefeat;
public:
    void Begin();
    void Win();
    void Defeat();
};

class Hero {
private:
    string name;
    unsigned short HeroHealth;
    unsigned short HeroChakra;
public:
    Hero(const string &name, unsigned short heroHealth, unsigned short heroChakra) : name(name), HeroHealth(heroHealth),
                                                                                     HeroChakra(heroChakra) {
        this->name = name;
        this->HeroHealth = HeroHealth;
        this->HeroChakra = HeroChakra;
    }
    const string &getName() const {
        return name;
    }
    unsigned short getHeroHealth() const {
        return HeroHealth;
    }
    unsigned short getHeroChakra() const {
        return HeroChakra;
    }
    void getHeroInfo() {
        cout << "Имя: " << getName() << "\nКоличество здоровья: " << getHeroHealth() << "\nКоличество чакры: " << getHeroChakra() << endl;
    }
};

/*class HeroWeapons {
private:
    short KunaiQuantity;
    short ShurikenQuantity;
public:
    HeroWeapons(short kunaiQuantity, short shurikenQuantity) : KunaiQuantity(kunaiQuantity),
                                                               ShurikenQuantity(shurikenQuantity) {
        this->KunaiQuantity = KunaiQuantity;
        this->ShurikenQuantity = ShurikenQuantity;
    }
    short getKunaiQuantity() const {
        return KunaiQuantity;
    }
    short getShurikenQuantity() const {
        return ShurikenQuantity;
    }
    void DecreaseKunaiQuantity() {
        KunaiQuantity--;
    }
    void DecreaseShurikenQuantity() {
        ShurikenQuantity--;
    }
    void WeaponPrint() {
        cout << "Количество кунаев: " << getKunaiQuantity() << endl;
        cout << "Количество сюрикенов: " << getShurikenQuantity() << endl;
    }
};*/

class HeroWeapon {
public:
    virtual string getWeaponName() const = 0;
    virtual unsigned short getWeaponQuantity() const = 0;
    virtual unsigned short getWeaponDamage() const = 0;
};

class NarutoFirstWeapon : public HeroWeapon {
public:
    string getWeaponName() const override {
        return "Кунаи";
    }
    unsigned short getWeaponQuantity() const override {
        return 5;
    }
    unsigned short getWeaponDamage() const override {
        return 100;
    }
};

class NarutoSecondWeapon : public HeroWeapon {
public:
    string getWeaponName() const override {
        return "Сюрикены";
    }
    unsigned short getWeaponQuantity() const override {
        return 10;
    }
    unsigned short getWeaponDamage() const override {
        return 50;
    }
};

class SasukeFirstWeapon : public HeroWeapon {
public:
    string getWeaponName() const override {
        return "Сюрикены";
    }
    unsigned short getWeaponQuantity() const override {
        return 10;
    }
    unsigned short getWeaponDamage() const override {
        return 100;
    }
};

class SasukeSecondWeapon : public HeroWeapon {
public:
    string getWeaponName() const override {
        return "Катана";
    }
    unsigned short getWeaponQuantity() const override {
        return 1;
    }
    unsigned short getWeaponDamage() const override {
        return 200;
    }
};

class SakuraFirstWeapon : public HeroWeapon {
public:
    string getWeaponName() const override {
        return "Кунаи";
    }
    unsigned short getWeaponQuantity() const override {
        return 3;
    }
    unsigned short getWeaponDamage() const override {
        return 80;
    }
};

class SakuraSecondWeapon : public HeroWeapon {
public:
    string getWeaponName() const override {
        return "Молот";
    }
    unsigned short getWeaponQuantity() const override {
        return 1;
    }
    unsigned short getWeaponDamage() const override {
        return 200;
    }
};

class WeaponPrint {
    vector<const HeroWeapon *> Weapon;
public:
    void addHeroWeapon(const HeroWeapon *weapon) {
        Weapon.push_back(weapon);
    }
    void printWeapon() {
        size_t size = Weapon.size();
        for (size_t i = 0; i < size; i++) {
            cout << "Оружие номер " << i+1 << ":" << endl;
            cout << "Название: " << Weapon[i]->getWeaponName() << endl;
            cout << "Количество: " << Weapon[i]->getWeaponQuantity() << endl;
            cout << "Количество урона: " << Weapon[i]->getWeaponDamage() << endl;
        }
    }
    void clearWeaponVector() {
        Weapon.clear();
    }
};

class AddWeapon {
    WeaponPrint myWeaponPrint;
public:
    void adding(Hero heroInfo) {
        if (heroInfo.getName() == "Наруто") {
            myWeaponPrint.addHeroWeapon(new NarutoFirstWeapon());
            myWeaponPrint.addHeroWeapon(new NarutoSecondWeapon());
        }
        if (heroInfo.getName() == "Саске") {
            myWeaponPrint.addHeroWeapon(new SasukeFirstWeapon());
            myWeaponPrint.addHeroWeapon(new SasukeSecondWeapon());
        }
        if (heroInfo.getName() == "Сакура") {
            myWeaponPrint.addHeroWeapon(new SakuraFirstWeapon());
            myWeaponPrint.addHeroWeapon(new SakuraSecondWeapon());
        }
        myWeaponPrint.printWeapon();
    }
    void cleaning() {
        myWeaponPrint.clearWeaponVector();
    }
};

class HeroAbility {
public:
    virtual string getAbilityName() const = 0;
    virtual unsigned short getAbilityDamage() const = 0;
    virtual unsigned short getAbilityChakra() const = 0;
};

class NarutoFirstAbility : public HeroAbility {
public:
    string getAbilityName() const override {
        return "Теневое Клонирование";
    }
    unsigned short getAbilityDamage() const override {
        return 100;
    }
    unsigned short getAbilityChakra() const override {
        return 200;
    }
};

class NarutoSecondAbility : public HeroAbility {
public:
    string getAbilityName() const override {
        return "Рассенган";
    }
    unsigned short getAbilityDamage() const override {
        return 300;
    }
    unsigned short getAbilityChakra() const override {
        return 400;
    }
};

class SasukeFirstAbility : public HeroAbility {
public:
    string getAbilityName() const override {
        return "Огненный шар";
    }
    unsigned short getAbilityDamage() const override {
        return 100;
    }
    unsigned short getAbilityChakra() const override {
        return 100;
    }
};

class SasukeSecondAbility : public HeroAbility {
public:
    string getAbilityName() const override {
        return "Чидори";
    }
    unsigned short getAbilityDamage() const override {
        return 300;
    }
    unsigned short getAbilityChakra() const override {
        return 300;
    }
};

class SakuraFirstAbility : public HeroAbility {
public:
    string getAbilityName() const override {
        return "Усиленный удар";
    }
    unsigned short getAbilityDamage() const override {
        return 100;
    }
    unsigned short getAbilityChakra() const override {
        return 80;
    }
};

class SakuraSecondAbility : public HeroAbility {
public:
    string getAbilityName() const override {
        return "Удар об землю";
    }
    unsigned short getAbilityDamage() const override {
        return 200;
    }
    unsigned short getAbilityChakra() const override {
        return 200;
    }
};

class AbilityPrint {
    vector<const HeroAbility *> Ability;
public:
    void addHeroAbility(const HeroAbility *ability) {
        Ability.push_back(ability);
    }
    void printAbility() {
        size_t size = Ability.size();
        for (size_t i = 0; i < size; i++) {
            cout << "Способность номер " << i+1 << ":" << endl;
            cout << "Название: " << Ability[i]->getAbilityName() << endl;
            cout << "Количество урона: " << Ability[i]->getAbilityDamage() << endl;
            cout << "Количество требуемой чакры: " << Ability[i]->getAbilityChakra() << endl;
        }
    }
    void clearAbilityVector() {
        Ability.clear();
    }
};

class AddAbilities {
    AbilityPrint myAbilityPrint;
public:
    void adding(Hero heroInfo) {
        if (heroInfo.getName() == "Наруто") {
            myAbilityPrint.addHeroAbility(new NarutoFirstAbility());
            myAbilityPrint.addHeroAbility(new NarutoSecondAbility());
        }
        if (heroInfo.getName() == "Саске") {
            myAbilityPrint.addHeroAbility(new SasukeFirstAbility());
            myAbilityPrint.addHeroAbility(new SasukeSecondAbility());
        }
        if (heroInfo.getName() == "Сакура") {
            myAbilityPrint.addHeroAbility(new SakuraFirstAbility());
            myAbilityPrint.addHeroAbility(new SakuraSecondAbility());
        }
        myAbilityPrint.printAbility();
    }
    void cleaning() {
        myAbilityPrint.clearAbilityVector();
    }
};

class HeroMenu {
    AddAbilities addAbilities;
    AddWeapon addWeapon;
public:
    short menuChoice = -1;
    void PrintHeroMenu(Hero heroInfo) {
        cout << "1. Посмотреть информацию о персонаже" << endl;
        cout << "2. Проверить боезапас" << endl;
        cout << "3. Посмотреть способности персонажа и их характеристики" << endl;
        cout << "0. Для выхода" << endl;

        do {
            cin >> menuChoice;
            switch (menuChoice) {
                case 1:
                    heroInfo.getHeroInfo();
                    cout << "Чтобы вернуться обратно, нажмите 4" << endl;
                    break;
                case 2:
                    addWeapon.cleaning();
                    addWeapon.adding(heroInfo);
                    cout << "Чтобы вернуться обратно, нажмите 4" << endl;
                    break;
                case 3:
                    addAbilities.cleaning();
                    addAbilities.adding(heroInfo);
                    cout << "Чтобы вернуться обратно, нажмите 4" << endl;
                    break;
                case 4:
                    PrintHeroMenu(heroInfo);
                    break;
            }
        } while (menuChoice > 0);
    }
};

class ContinueMenu {
    HeroMenu heroMenu;
public:
    void ContinueMenuPrint(Hero heroInfo) {
        short startChoice = -1;
        cout << "1. Перейти в меню персонажа" << endl;
        cout << "2. Перейти к сражению" << endl;
        cout << "0. Для выхода" << endl;

        do {
            cin >> startChoice;
            switch (startChoice) {
                case 1:
                    heroMenu.PrintHeroMenu(heroInfo);
                    cout << "Чтобы перейти к выбору персонажа, нажмите 0" << endl;
                    cout << "Нажмите 3 для входа в меню продолжения" << endl;
                    break;
                    //case 2:
                    //  StartFight();
                    //break;
                case 3:
                    ContinueMenuPrint(heroInfo);
                    //cout << "Нажмите 4 для перехода к выбору персонажа" << endl;
                    break;
            }
        } while (startChoice > 0);
    }
};

class HeroBuild {
    ContinueMenu continueMenu;
public:
    void NarutoBuild() {
        Hero heroInfo("Наруто", 500, 1000);
        continueMenu.ContinueMenuPrint(heroInfo);
    }
    void SasukeBuild() {
        Hero heroInfo("Саске", 400, 800);
        continueMenu.ContinueMenuPrint(heroInfo);
    }
    void SakuraBuild() {
        Hero heroInfo("Сакура", 300, 600);
        continueMenu.ContinueMenuPrint(heroInfo);
    }
};

class SelectHero {
    HeroBuild selectHero;
public:
    short choice = -1;
    void Select_Hero() {
        cout << "Выберите персонажа" << endl;
        cout << "1. Наруто" << endl;
        cout << "2. Саске" << endl;
        cout << "3. Сакура" << endl;
        cout << "0. Для выхода" << endl;

        do {
            cin >> choice;
            switch (choice) {
                case 1:
                    selectHero.NarutoBuild();
                    cout << "Хотите взглянуть на список героев еще раз? - нажмите 4. Иначе нажмите 1,2 или 3 в зависимости от номера персонажа" << endl;
                    break;
                case 2:
                    selectHero.SasukeBuild();
                    cout << "Хотите взглянуть на список героев еще раз? - нажмите 4. Иначе нажмите 1,2 или 3 в зависимости от номера персонажа" << endl;
                    break;
                case 3:
                    selectHero.SakuraBuild();
                    cout << "Хотите взглянуть на список героев еще раз? - нажмите 4. Иначе нажмите 1,2 или 3 в зависимости от номера персонажа" << endl;
                    break;
                case 4:
                    Select_Hero();
                    break;
            }
        } while(choice > 0);
        cout << "3. Для выхода в главное меню" << endl;
    }
};

class MainMenu  {
private:
    SelectHero mainMenu;
public:
    int GameStart() {
        short GameStartChoice = -1;
        cout << "Здравствуйте. Вас приветствует игра <<Наруто. Стань лучшим ниндзя>>" << endl;
        cout << "1. Перейти к выбору персонажа" << endl;
        cout << "2. Выйти из игры" << endl;

        do {
            cin >> GameStartChoice;
            switch (GameStartChoice) {
                case 1:
                    mainMenu.Select_Hero();
                    break;
                case 2:
                    cout << "Вы точно хотите выйти? 0 - чтобы выйти, 3 - чтобы вернуться в стартовое меню" << endl;
                    break;
                case 3:
                    GameStart();
                    break;
            }
        } while (GameStartChoice > 0);
        cout << "До свидания" << endl;
        return 0;
    }
};

int main() {
    MainMenu play;
    play.GameStart();
    return 0;
}

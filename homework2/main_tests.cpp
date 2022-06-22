#define CATCH_CONFIG_MAIN

#include "catch2.hpp"
#include "main.cpp"

SCENARIO("Character creation"){
    GIVEN("No character"){
        Character* c = nullptr;
        THEN("Create new character with invalid name"){
            REQUIRE_THROWS(c=new Character("",10,10));
        }
        THEN("Create new character with invalid health"){
            REQUIRE_THROWS(c=new Character("a",-1,10));
        }
        THEN("Create new character with invalid defence"){
            REQUIRE_THROWS(c=new Character("a", 10, -1));
        }
        THEN("Create new character"){
            Character c("test", 10, 10);
            REQUIRE(c.getName() == "test");
            REQUIRE(c.getHealth() == 10);
            REQUIRE(c.getDefense() == 10);
        }
        delete c;
    }

    GIVEN("Character"){
        Character c("test", 10, 10);
        THEN("Set invalid name"){
            REQUIRE_THROWS(c.setName(""));
            REQUIRE(c.getName() == "test");
        }

        THEN("Set invalid health"){
            REQUIRE_THROWS(c.setHealth(-1));
        }
        THEN("Set invalid defence"){
            REQUIRE_THROWS(c.setDefense(-1));
        }
        THEN("Set valid values"){
            c.setName("test1");
            c.setHealth(100);
            c.setDefense(100);

            REQUIRE(c.getName() == "test1");
            REQUIRE(c.getHealth() == 100);
            REQUIRE(c.getDefense() == 100);
        }
    }
}
SCENARIO("Enemy creation"){
    GIVEN("No enemy"){
        Enemy* e;
        THEN("Create enemy with invalid damage"){
            REQUIRE_THROWS(e = new Enemy("test", 10, 10, -1));
        }
        THEN("Create enemy with valid damage"){
            REQUIRE_NOTHROW(e = new Enemy("test", 10, 10, 100));
        }
    }
    GIVEN("Enemy"){
        Enemy e("test", 10, 10, 100);
        THEN("Set invalid damage"){
            REQUIRE_THROWS(e.setDamage(-10));
        }
    }
}

SCENARIO("Ability creation"){
    GIVEN("No ability"){
        Ability* e;

        THEN("Create ability with invalid name"){
            REQUIRE_THROWS(e = new Ability("", 10));
        }
        THEN("Create ability with valid damage"){
            REQUIRE_THROWS(e = new Ability("test", -10));
        }
        THEN("Create valid ability"){
            REQUIRE_NOTHROW(e = new Ability("test",100));
            REQUIRE(e->getName() == "test");
            REQUIRE(e->getDamage() == 100);
        }
    }

    GIVEN("Valid ability"){
        Ability e("test", 100);

        THEN("Set invalid name"){
            REQUIRE_THROWS(e.setName(""));
        }

        THEN("Set invalid damage"){
            REQUIRE_THROWS(e.setDamage(-10));
        }

        THEN("Set valid values"){
            e.setName("test1");
            e.setDamage(10);

            REQUIRE(e.getName() == "test1");
            REQUIRE(e.getDamage() == 10);
        }
    }
}

SCENARIO("Add ability to Player"){
    GIVEN("Player"){
        Ability a1("test1", 1000);
        Ability a2("test2", 10);
        std::vector<Ability> abilities = {a1};
        Player p("test", 100, 100, abilities);


        THEN("Add ability to non-empty vector"){
            p.addAbility(a2);

            REQUIRE(p.getAbilities().at(1).getName() == "test2");
            REQUIRE(p.getAbilities().at(1).getDamage() == 10);
        }
        THEN("Add duplicate ability to non-empty vector"){
            REQUIRE_THROWS(p.addAbility(a1));
        }
    }
}

SCENARIO("Calculate player damage"){
    GIVEN("Player with abilities"){
        Ability a1("test1", 1000);
        Ability a2("test2", 10);
        std::vector<Ability> abilities = {a1, a2};
        Player p("test", 100, 100, abilities);

    
        THEN("Calculate"){
            REQUIRE(PlayerHelper::getTotalPlayerDamage(p) == 1010);
        }
    }
}

SCENARIO("Arena fighting"){
    GIVEN("Arena with player with abilities and enemies"){
        
        Ability a1("test", 392);
        Ability a2("test2", 108);
        std::vector<Ability> abilities = {a1, a2};
        Player p("test", 100, 50, abilities);
        
        Enemy e1("e1", 50, 50, 20);
        Enemy e2("e2", 50, 50, 20);
        vector<Enemy> enemies = {e1, e2};

        THEN("Player should win"){
            REQUIRE(Arena::fight(p, enemies) == true);
            REQUIRE(p.getDefense() == 0);
            REQUIRE(p.getHealth() == 100);
            REQUIRE(enemies[0].getDefense() == 0);
            REQUIRE(enemies[0].getHealth() == 0);
            REQUIRE(enemies[1].getDefense() == 0);
            REQUIRE(enemies[1].getHealth() == 0);
            REQUIRE(Arena::currentEnemyIndex == 2);
        }
    }
    GIVEN("Arena with player with abilities and enemies"){
        Ability a1("test", 10);
        Ability a2("test2", 20);
        std::vector<Ability> abilities = {a1, a2};
        Player p("test", 100, 100, abilities);
        
        Enemy e1("e1", 20, 20, 150);
        Enemy e2("e2", 1000, 1000, 150);
        vector<Enemy> enemies = {e1, e2};


        THEN("Player should lose"){
            REQUIRE(Arena::fight(p,  enemies) == false);
            REQUIRE(p.getDefense() == 0);
            REQUIRE(p.getHealth() == 0);
            REQUIRE(enemies[0].getDefense() == 0);
            REQUIRE(enemies[0].getHealth() == 0);
            REQUIRE(enemies[1].getDefense() == 1000);
            REQUIRE(enemies[1].getHealth() == 1000);
            REQUIRE(Arena::currentEnemyIndex == 1);
        }

    }
}
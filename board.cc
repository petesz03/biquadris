#include "board.h"


Board::Board(Player* owner, Level* owners_level):
    owner{owner}, owners_level{owners_level} {
        isblind = false;
        isheavy = false;
        isforce = false;
        current = nullptr;
        max_height = 0;
        num_of_full = 0;
        start_action = false;
    }

Board::~Board() {
    
}


void Board::checkfullrow() {
    std::vector<int> v;
    for (auto a : row2) {
        if (a->box1.y == 0) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 0) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 0) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 0) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(0);
    }
    v.clear();
    for (auto a : row1) {
        if (a->box1.y == 1) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 1) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 1) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 1) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(1);
    }
    v.clear();
    for (auto a : row2) {
        if (a->box1.y == 2) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 2) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 2) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 2) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(2);
    }
    v.clear();
    for (auto a : row3) {
        if (a->box1.y == 3) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 3) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 3) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 3) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(3);
    }
    v.clear();
    for (auto a : row4) {
        if (a->box1.y == 4) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 4) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 4) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 4) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(4);
    }
    v.clear();
    for (auto a : row5) {
        if (a->box1.y == 5) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 5) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 5) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 5) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(5);
    }
    v.clear();
    for (auto a : row6) {
        if (a->box1.y == 6) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 6) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 6) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 6) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(6);
    }
    v.clear();
    for (auto a : row7) {
        if (a->box1.y == 7) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 7) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 7) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 7) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(7);
    }
    v.clear();
    for (auto a : row8) {
        if (a->box1.y == 8) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 8) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 8) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 8) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(8);
    }
    v.clear();
    for (auto a : row9) {
        if (a->box1.y == 9) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 9) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 9) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 9) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(9);
    }
    v.clear();
    for (auto a : row10) {
        if (a->box1.y == 10) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 10) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 10) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 10) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(10);
    }
    v.clear();
    for (auto a : row11) {
        if (a->box1.y == 11) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 11) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 11) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 11) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(11);
    }
    v.clear();
    for (auto a : row12) {
        if (a->box1.y == 12) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 12) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 12) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 12) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(12);
    }
    v.clear();
    for (auto a : row13) {
        if (a->box1.y == 13) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 13) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 13) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 13) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(13);
    }
    v.clear();
    for (auto a : row14) {
        if (a->box1.y == 14) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 14) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 14) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 14) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(14);
    }
    v.clear();
    for (auto a : row15) {
        if (a->box1.y == 15) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 15) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 15) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 15) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(15);
    }
    v.clear();
    for (auto a : row16) {
        if (a->box1.y == 16) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 16) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 16) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 16) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(16);
    }
    v.clear();
    for (auto a : row17) {
        if (a->box1.y == 17) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 17) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 17) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 17) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(17);
    }
    v.clear();
}


void Board::clearrow() {
    for (auto a : to_free) {
        if (a == 0) {
            for (auto b : row0) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 0);
                }
            }
        }
        if (a == 1) {
            for (auto b : row1) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 1);
                }
            }
        }
        if (a == 2) {
            for (auto b : row2) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 2);
                }
            }
        }
        if (a == 3) {
            for (auto b : row3) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 3);
                }
            }
        }
        if (a == 4) {
            for (auto b : row4) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 4);
                }
            }
        }
        if (a == 5) {
            for (auto b : row5) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 5);
                }
            }
        }
        if (a == 6) {
            for (auto b : row6) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 6);
                }
            }
        }
        if (a == 7) {
            for (auto b : row7) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 7);
                }
            }
        }
        if (a == 8) {
            for (auto b : row8) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 8);
                }
            }
        }
        if (a == 9) {
            for (auto b : row9) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 9);
                }
            }
        }
        if (a == 10) {
            for (auto b : row10) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 10);
                }
            }
        }
        if (a == 11) {
            for (auto b : row11) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 11);
                }
            }
        }
        if (a == 12) {
            for (auto b : row12) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 12);
                }
            }
        }
        if (a == 13) {
            for (auto b : row13) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 13);
                }
            }
        }
        if (a == 14) {
            for (auto b : row14) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 14);
                }
            }
        }
        if (a == 15) {
            for (auto b : row15) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 15);
                }
            }
        }
        if (a == 16) {
            for (auto b : row16) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 16);
                }
            }
        }
        if (a == 17) {
            for (auto b : row17) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 17);
                }
            }
        }
    }
}



Block* Board::createBlock() {
    if (owners_level->level() == 1) {
        int value = rand() % 12;
        if (value == 0) {
            current = new Sblock{0, true, 1};
        } else if (value == 1) {
            current = new Zblock{0, true, 1};
        } else if (value == 2) {
            current = new Iblock{0, true, 1};
        } else if (value == 3) {
            current = new Iblock{0, true, 1};
        } else if (value == 4) {
            current = new Jblock{0, true, 1};
        } else if (value == 5) {
            current = new Jblock{0, true, 1};
        } else if (value == 6) {
            current = new Lblock{0, true, 1};
        } else if (value == 7) {
            current = new Lblock{0, true, 1};
        } else if (value == 8) {
            current = new Oblock{0, true, 1};
        } else if (value == 9) {
            current = new Oblock{0, true, 1};
        } else if (value == 10) {
            current = new Tblock{0, true, 1};
        } else if (value == 11) {
            current = new Tblock{0, true, 1};
        }
    }
    if (owners_level->level() == 2) {
        int value = rand() % 7;
        if (value == 0) {
            current = new Iblock{0, true, 1};
        } else if (value == 1) {
            current = new Jblock{0, true, 1};
        } else if (value == 2) {
            current = new Lblock{0, true, 1};
        } else if (value == 3) {
            current = new Oblock{0, true, 1};
        } else if (value == 4) {
            current = new Sblock{0, true, 1};
        } else if (value == 5) {
            current = new Zblock{0, true, 1};
        } else if (value == 6) {
            current = new Tblock{0, true, 1};
        }
    }

    if (owners_level->level() == 3) {
        int value = rand() % 9;
        if (value == 0) {
            current = new Sblock{0, true, 1};
        } else if (value == 1) {
            current = new Sblock{0, true, 1};
        } else if (value == 2) {
            current = new Zblock{0, true, 1};
        } else if (value == 3) {
            current = new Zblock{0, true, 1};
        } else if (value == 4) {
            current = new Iblock{0, true, 1};
        } else if (value == 5) {
            current = new Jblock{0, true, 1};
        } else if (value == 6) {
            current = new Lblock{0, true, 1};
        } else if (value == 7) {
            current = new Oblock{0, true, 1};
        } else if (value == 8) {
            current = new Tblock{0, true, 1};
        }
    }

    if (owners_level->level() == 4) {
        int value = rand() % 9;
        if (value == 0) {
            current = new Sblock{0, true, 1};
        } else if (value == 1) {
            current = new Sblock{0, true, 1};
        } else if (value == 2) {
            current = new Zblock{0, true, 1};
        } else if (value == 3) {
            current = new Zblock{0, true, 1};
        } else if (value == 4) {
            current = new Iblock{0, true, 1};
        } else if (value == 5) {
            current = new Jblock{0, true, 1};
        } else if (value == 6) {
            current = new Lblock{0, true, 1};
        } else if (value == 7) {
            current = new Oblock{0, true, 1};
        } else if (value == 8) {
            current = new Tblock{0, true, 1};
        }
    }
}



Block* Board::get_current() {
    return current;
}






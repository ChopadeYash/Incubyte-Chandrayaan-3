#include <iostream>
#include <vector>
using namespace std;

class SpaceProbe {
private:
    int xPos, yPos, zPos;
    char direction;

public:
    SpaceProbe() {
        xPos = yPos = zPos = 0;
        direction = 'O';
    }

    SpaceProbe(int x, int y, int z, char dir) {
        xPos = x;
        yPos = y;
        zPos = z;
        direction = dir;
    }

    int getX() {
        return xPos;
    }

    int getY() {
        return yPos;
    }

    int getZ() {
        return zPos;
    }

    char getDirection() {
        return direction;
    }

    void addToX(int xIncrement) {
        xPos += xIncrement;
    }

    void addToY(int yIncrement) {
        yPos += yIncrement;
    }

    void addToZ(int zIncrement) {
        zPos += zIncrement;
    }

    void setDirection(char newDir) {
        direction = newDir;
    }

    void printFinalStatus() {
        cout << "Final Coordinates: (" << xPos << "," << yPos << "," << zPos << ")\n";
        cout << "Final Direction: " << direction << endl;
    }
};

int main() {
    // cout << "Enter initial coordinates (x, y, z)\n";
    int x, y, z;
    // cout << "Enter x coordinate: ";
    cin >> x;
    // cout << "Enter y coordinate: ";
    cin >> y;
    // cout << "Enter z coordinate: ";
    cin >> z;

    char initialDirection;
    cout << "Enter initial direction: ";
    cin >> initialDirection;

    SpaceProbe probe(x, y, z, initialDirection);

    // cout << "Enter commands and enter '0' after inputting all commands to terminate input:\n";

    vector<char> commands;
    char command;
    while (cin >> command) {
        if (command == '0') {
            break;
        } else {
            commands.push_back(command);
        }
    }
    char temp;
    for (char c : commands) {
        switch (c) {
            case 'u':
                probe.setDirection('U');
                break;

            case 'd':
                probe.setDirection('D');
                break;

            case 'l':
                temp = probe.getDirection();
                if (temp == 'N') {
                    probe.setDirection('W');
                } else if (temp == 'E') {
                    probe.setDirection('N');
                } else if (temp == 'S') {
                    probe.setDirection('E');
                } else if (temp == 'W') {
                    probe.setDirection('S');
                } else if (temp == 'U') {
                    probe.setDirection('N');
                } else if (temp == 'D') {
                    probe.setDirection('S');
                }
                break;

            case 'r':
                temp = probe.getDirection();
                if (temp == 'N') {
                    probe.setDirection('E');
                } else if (temp == 'E') {
                    probe.setDirection('S');
                } else if (temp == 'S') {
                    probe.setDirection('W');
                } else if (temp == 'W') {
                    probe.setDirection('N');
                } else if (temp == 'U') {
                    probe.setDirection('S');
                } else if (temp == 'D') {
                    probe.setDirection('N');
                }
                break;

            case 'f':
                temp = probe.getDirection();
                if (temp == 'N') {
                    probe.addToY(1);
                } else if (temp == 'E') {
                    probe.addToX(1);
                } else if (temp == 'S') {
                    probe.addToY(-1);
                } else if (temp == 'W') {
                    probe.addToX(-1);
                } else if (temp == 'U') {
                    probe.addToZ(1);
                } else if (temp == 'D') {
                    probe.addToZ(-1);
                }
                break;

            case 'b':
                temp = probe.getDirection();
                if (temp == 'N') {
                    probe.addToY(-1);
                } else if (temp == 'E') {
                    probe.addToX(-1);
                } else if (temp == 'S') {
                    probe.addToY(1);
                } else if (temp == 'W') {
                    probe.addToX(1);
                } else if (temp == 'U') {
                    probe.addToZ(-1);
                } else if (temp == 'D') {
                    probe.addToZ(1);
                }
                break;

            default:
                break;
        }
    }

    cout << "\nFinal Configuration of Space Probe\n";
    probe.printFinalStatus();

    return 0;
}

#include "stdafx.h"
#include <windows.h>
#include <memory>

class progressbar
{
#define TEXT_LENGTH 51
public:
    progressbar() {
        mask = '#';
        reset();
    }

    void show(const char *head, const char *tail, int max, int current) {
        if (current > max) {
            current = max;
        }
        if (head == nullptr) {
            head = "";
        }
        if (tail == nullptr) {
            tail = "";
        }
        int percentage = (int)(((float)current / (float)max) * 100.0f);
        int currentPosition = percentage / 2;
        memset(progress, mask, currentPosition);
        printf("%s[%-s] %d%% %s\r",
            head, progress, percentage, tail);
        fflush(stdout);
    }

    void setMask(const char mask) {
        this->mask = mask;
    }

    const char getMask() const {
        return mask;
    }

    void reset() {
        memset(progress, 32, TEXT_LENGTH - 1);
        progress[TEXT_LENGTH - 1] = '\0';
    }
private:
    char progress[TEXT_LENGTH];
    int max;
    char mask;
};

int main() {
    progressbar pgbar;
    const int max = 200;
    for (int i = 0; i < max; i++) {
        pgbar.show("download:", "1.2M/S", max, i + 1);
        Sleep(100);
    }
    printf("\n");
    return 0;
}

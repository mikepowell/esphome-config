#include "esphome.h"
using namespace esphome;

const int LOW_SPEED_PIN = 14;
const int MED_SPEED_PIN = 12;
const int HIGH_SPEED_PIN = 15;

class IFan03Output : public Component, public FloatOutput {
public:
    void write_state(float state) override {
        if (state < 0.3)
        {
            // OFF
            set_speed_relays(LOW, LOW, LOW);
        }
        else if (state < 0.6)
        {
            // low speed
            set_speed_relays(HIGH, LOW, LOW);
        }
        else if (state < 0.9)
        {
            // medium speed
            set_speed_relays(HIGH, HIGH, LOW);
        }
        else
        {
            // high speed
            set_speed_relays(HIGH, LOW, HIGH);
        }
    }
private:
    void set_speed_relays(int low, int med, int high) {
        digitalWrite(LOW_SPEED_PIN, low);
        digitalWrite(MED_SPEED_PIN, med);
        digitalWrite(HIGH_SPEED_PIN, high);
    }
};

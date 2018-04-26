#include <Builder_demoMerlin_ardu.h>

Scheduler *scheduler;

void setup() {
    Builder *builder = new Builder_demoMerlin_ardu();
    scheduler = builder->build();
}

void loop() {
    scheduler->update();
}

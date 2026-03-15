typedef struct{
    int pos;
    int spd;
    float time;
}Car;

int compareCars(const void* a, const void* b) {
    return (((Car*)a)->pos - ((Car*)b)->pos);
}



int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    if(positionSize == 1){
        return 1;
    }

    Car* cars = (Car*)malloc(sizeof(Car) * positionSize);
    for (int i = 0; i < positionSize; i++) {
        cars[i].pos = position[i];
        cars[i].spd = speed[i];
        cars[i].time = (float) (target - position[i]) / (float) speed[i];
    }

    qsort(cars, positionSize, sizeof(Car), compareCars);

    int fleet = 0;
    float max_time = 0.0;

    for(int i = positionSize - 1; i >= 0; i--){
        if(cars[i].time > max_time){
            fleet++;
            max_time = cars[i].time;
        }
    }
    return fleet;
}

package Programs;

import Programs.OOPS.Car;

class Test {
    public static void main(String[] args) {
        Car myCar = new Car("Red", "Model S", "Tesla", 2020, 100);
        myCar.displayDetails();
        myCar.accelerate(20);
        myCar.brake(50);
        myCar.brake(80); // This will set speed to 0
        System.out.println("Current Speed: " + myCar.getSpeed() + " km/h");
    }
}
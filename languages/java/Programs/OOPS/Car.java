package Programs.OOPS;

public class Car {
    String colorl;
    String model;
    String brand;
    int year;
    int speed;

    public Car(String colorl, String model, String brand, int year, int speed) {
        this.colorl = colorl;
        this.model = model;
        this.brand = brand;
        this.year = year;
        this.speed = speed;
    }

    public void displayDetails() {
        System.out.println("Car Details:");
        System.out.println("Color: " + colorl);
        System.out.println("Model: " + model);
        System.out.println("Brand: " + brand);
        System.out.println("Year: " + year);
        System.out.println("Speed: " + speed + " km/h");
    }

    public void accelerate(int increment) {
        speed += increment;
        System.out.println("Accelerated to: " + speed + " km/h");
    }

    public void brake(int decrement) {
        speed -= decrement;
        if (speed < 0) {
            speed = 0;
        }
        System.out.println("Braked to: " + speed + " km/h");
    }

    public int getSpeed() {
        return speed;
    }
}

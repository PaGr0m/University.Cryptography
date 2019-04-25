package com.festu;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {

//        task_1();
        task_2();
    }

    public static void task_1() {
        List<Patient> patientList = new ArrayList<>();

        patientList.add(new Patient(1, "Zvonov", "Nilolay", "Yurevich",
                "Khv1", "8-914-111-22-33", "1111", "Слишком умный"));
        patientList.add(new Patient(2, "Gromov", "Pavel", "Alekseevich",
                "Khv2", "8-914-444-55-66", "2222", "Слишком старый"));
        patientList.add(new Patient(3, "Martinova", "Julia", "Romanovna",
                "Khv3", "8-914-777-88-99", "3333", "Слишком красивая"));


        for (Patient patient: patientList) {
            if(patient.diagnosis == "Слишком красивая")
                System.out.println(patient.toString());
        }

        System.out.println("--------------------------------------");
        for (Patient patient: patientList) {
            if (Integer.parseInt(patient.medicalRecord) > 1000 && Integer.parseInt(patient.medicalRecord) < 3000)
                System.out.println(patient.toString());
        }
    }

    public static void task_2() {

        List<Computer> computerList = new ArrayList<>();

        computerList.add(new Computer(1, new Computer.Info("Windows", "16 Gb", "Intel 7")));
        computerList.add(new Computer(2, new Computer.Info("Linux", "32 Gb", "Intel 10")));

        for (Computer computer: computerList) {
            System.out.println(computer);
        }
    }
}





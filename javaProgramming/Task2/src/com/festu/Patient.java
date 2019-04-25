package com.festu;

public class Patient {

    long id;
    String surname;
    String name;
    String fatherName;
    String address;
    String phone;
    String medicalRecord;
    String diagnosis;

    @Override
    public String toString() {
        return this.id + " " + this.surname + " " + this.name + " " + this.surname + " " + this.fatherName + " " +
                this.address + " " +  this.phone + " " + this.diagnosis + " " + this.medicalRecord;
    }

    public Patient() {
    }

    public Patient(long id, String surname, String name, String fatherName, String address, String phone, String medicalRecord, String diagnosis) {
        this.id = id;
        this.surname = surname;
        this.name = name;
        this.fatherName = fatherName;
        this.address = address;
        this.phone = phone;
        this.medicalRecord = medicalRecord;
        this.diagnosis = diagnosis;
    }
}

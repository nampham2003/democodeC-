package model;
import java.util.Date;

public class Instructor {
  String id,name;Date dob; boolean gender;
   Subject sub;

    public Instructor() {
    }

    public Instructor(String id, String name, Date dob, boolean gender, Subject sub) {
        this.id = id;
        this.name = name;
        this.dob = dob;
        this.gender = gender;
        this.sub = sub;
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public Date getDob() {
        return dob;
    }

    public boolean isGender() {
        return gender;
    }

    public Subject getSub() {
        return sub;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setDob(Date dob) {
        this.dob = dob;
    }

    public void setGender(boolean gender) {
        this.gender = gender;
    }

    public void setSub(Subject sub) {
        this.sub = sub;
    }

    
}

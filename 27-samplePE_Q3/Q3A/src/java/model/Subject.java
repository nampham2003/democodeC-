package model;

public class Subject {
    String sid,sname;

    public Subject() {
    }

    public Subject(String sid, String sname) {
        this.sid = sid;
        this.sname = sname;
    }

    public String getSid() {
        return sid;
    }

    public String getSname() {
        return sname;
    }

    public void setSid(String sid) {
        this.sid = sid;
    }

    public void setSname(String sname) {
        this.sname = sname;
    }

    
}

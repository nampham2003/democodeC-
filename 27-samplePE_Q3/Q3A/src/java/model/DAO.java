package model;
import java.util.*;

public class DAO extends MyDAO {
    
  public List<Subject> getSubjects() {
    String xSid,xSname;
    Subject x;
    List<Subject> t = new ArrayList<>();
    xSql = "select * from Subjects";
    try {
      ps = con.prepareStatement(xSql);
      rs = ps.executeQuery();
      while(rs.next()) {
        xSid = rs.getString("SubjectId");  
        xSname = rs.getString("SubjectName");  
        x = new Subject(xSid,xSname);
        t.add(x);
      }
      rs.close();
      ps.close();
     }
     catch(Exception e) {
        e.printStackTrace();
     }
    return(t);
  }

  public List<Instructor> getInstructors() {    
    List<Instructor> t = new ArrayList<Instructor>();
    String xId,xName; Date xDob; boolean xGender;Subject xSub;
    String xSub_id,xSub_name;
    Instructor x = null;
    xSql = "select u.InstructorID,u.InstructorName,u.Gender,u.BirthDate,u.SubjectId,v.SubjectName ";
    xSql += " from Instructors as u,Subjects as v ";
    xSql += " where u.SubjectID = v.SubjectId";
    try {
      ps = con.prepareStatement(xSql);
      rs = ps.executeQuery();
      while(rs.next()) {
        xId = rs.getString("InstructorID");  
        xName = rs.getString("InstructorName");  
        xGender = rs.getBoolean("Gender");
        xDob = rs.getDate("BirthDate");
        xSub_id = rs.getString("SubjectId");
        xSub_name = rs.getString("SubjectName");
        xSub = new Subject(xSub_id,xSub_name);
        x = new Instructor(xId,xName,xDob,xGender,xSub);
        t.add(x);
      }
      rs.close();
      ps.close();
     }
     catch(Exception e) {
        e.printStackTrace();
     }
    return(t);
  }
  public Instructor getInstructor(String xId) {    
    String xName; Date xDob; boolean xGender;Subject xSub;
    String xSub_id,xSub_name;
    Instructor x =null;
    xSql = "select u.InstructorID,u.InstructorName,u.Gender,u.BirthDate,u.SubjectId,v.SubjectName ";
    xSql += " from Instructors as u,Subjects as v ";
    xSql += " where u.SubjectID = v.SubjectId and u.InstructorId = ?";
    try {
      ps = con.prepareStatement(xSql);
      ps.setString(1, xId);
      rs = ps.executeQuery();
      while(rs.next()) {
        xName = rs.getString("InstructorName");  
        xGender = rs.getBoolean("Gender");
        xDob = rs.getDate("BirthDate");
        xSub_id = rs.getString("SubjectId");
        xSub_name = rs.getString("SubjectName");
        xSub = new Subject(xSub_id,xSub_name);
        x = new Instructor(xId,xName,xDob,xGender,xSub);
      }
      rs.close();
      ps.close();
     }
     catch(Exception e) {
        e.printStackTrace();
     }
    return(x);
  }
  public List<Instructor> getInstructors(String xSid) {    
    List<Instructor> t = new ArrayList<Instructor>();
    String xId,xName; Date xDob; boolean xGender;Subject xSub;
    String xSub_id,xSub_name;
    Instructor x =null;
    xSql = "select u.InstructorID,u.InstructorName,u.Gender,u.BirthDate,u.SubjectId,v.SubjectName ";
    xSql += " from Instructors as u,Subjects as v ";
    xSql += " where u.SubjectID = v.SubjectId and u.SubjectId = ?";
    try {
      ps = con.prepareStatement(xSql);
      ps.setString(1, xSid);
      rs = ps.executeQuery();
      while(rs.next()) {
        xId = rs.getString("InstructorID");  
        xName = rs.getString("InstructorName");  
        xGender = rs.getBoolean("Gender");
        xDob = rs.getDate("BirthDate");
        xSub_id = rs.getString("SubjectId");
        xSub_name = rs.getString("SubjectName");
        xSub = new Subject(xSub_id,xSub_name);
        x = new Instructor(xId,xName,xDob,xGender,xSub);
        t.add(x);
      }
      rs.close();
      ps.close();
     }
     catch(Exception e) {
        e.printStackTrace();
     }
    return(t);
  }
  
}

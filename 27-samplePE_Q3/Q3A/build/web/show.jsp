<%@page import="java.util.*" %>
<%@page import="model.*"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix = "c" uri = "http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<%
  DAO u = new DAO();
  List<Subject> lst1 = u.getSubjects();  
  String xId = (String) request.getAttribute("xId");
  String xSid = (String) request.getAttribute("xSid");
  Instructor xIns = (Instructor) request.getAttribute("xIns");
  List<Instructor> lst = (List<Instructor>) request.getAttribute("lst");
%>    
<html>
  <head>
     <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
     <title>JSP Page</title>
  </head>
  <body>
     <form action="show" method="POST">
       List of subjects:  
       <select name="sub" onchange="this.form.submit()">
          <option value="0"> All subjects> </option>
       <% for(Subject x: lst1) {
          if(x.getSid().equals(xSid)) { %>
          <option value="<%= x.getSid() %>" selected > <%= x.getSname() %> </option>
         <% }
          else
         %> 
          <option value="<%= x.getSid() %>"> <%= x.getSname() %> </option>
       <% } %>
         </select>

       <p>List of Instructors:
         <table border="1">
           <tr>
            <td>Code</td>
            <td>Name</td>
            <td>Date of birth</td>
            <td>Gender</td>
            <td>Subject</td>
            <td>Select</td>
           </tr>
       <% for(Instructor x: lst) { %>
           <tr>
            <td><%= x.getId()%></td>
            <td><%= x.getName()%></td>
            <td><%= x.getDob()%> </td>
            <td><% if(x.isGender()){%>
                Male
              <%} else {%>
                Female
              <% } %>  
            </td>
            <td><%= x.getSub().getSname()%> </td>
            <td><a href="show?id=<%=x.getId()%>&sub=<%=xSid%>">Select</a></td>
           </tr>
       <% } %>    
       </table>

       <p>Detail information:

       <table>
          <tr>
            <td>Code:</td>
            <td><input type="text" name="code" value="${xIns.getId()}"></td>
            <td>Name:</td>
            <td><input type="text" name="name" value="${xIns.getName()}"></td>
           </tr>
           <tr>
            <td>Date of birth:</td>
            <td><input type="text" name="dob" value="${xIns.getDob()}"></td>
            <td>Gender:</td>
            <td>
              <c:choose>
                <c:when test="${xIns.isGender()==true}">
                    <input type="radio" name="gender" checked>Male
                    <input type="radio" name="gender">Female
                </c:when>
                <c:otherwise>
                    <input type="radio" name="gender">Male
                    <input type="radio" name="gender" checked>Female
                </c:otherwise>
               </c:choose>
            </td>
           </tr>
           <tr>
            <td>Subject:</td>
            <td>
              <input type="text" value="${xIns.getSub().getSid()}">
            </td>
            <td></td>
            <td></td>
           </tr>
       </table>

     </form>    
  </body>
</html>

package controller;
import model.*;
import java.util.*;

import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;

public class ShowServlet extends HttpServlet {

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        String xId,xSid; Instructor xIns;
        List<Instructor> lst;
        xId = request.getParameter("id");
        xSid = request.getParameter("sub");
        //out.print("id = " + xId + ", Sid = " + xSid);
        DAO u = new DAO();
        if(xId==null)
            xIns = null;
        else {
            xIns = u.getInstructor(xId);
        }
        if(xSid==null || xSid.equals("0"))
           lst = u.getInstructors();
           else
           lst = u.getInstructors(xSid);
        request.setAttribute("xId",xId);
        request.setAttribute("xSid",xSid);
        request.setAttribute("xIns",xIns);
        request.setAttribute("lst",lst);
        request.getRequestDispatcher("show.jsp").forward(request, response);
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        String xId,xSid; Instructor xIns;
        List<Instructor> lst;
        xId = request.getParameter("id");
        xSid = request.getParameter("sub");
        out.print("id = " + xId + ", Sid = " + xSid);
        DAO u = new DAO();
        if(xId==null)
            xIns = null;
        else {
            xIns = u.getInstructor(xId);
        }
        if(xSid==null || xSid.equals("0"))
           lst = u.getInstructors();
           else
           lst = u.getInstructors(xSid);
        request.setAttribute("xId",xId);
        request.setAttribute("xSid",xSid);
        request.setAttribute("xIns",xIns);
        request.setAttribute("lst",lst);
        request.getRequestDispatcher("show.jsp").forward(request, response);
    }
}


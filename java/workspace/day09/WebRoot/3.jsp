<%@page import="cn.wang.Add"%>
<%@page import="cn.wang.Person"%>
<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>

<title>el表达式</title>

</head>

<body>
	<%
		request.setAttribute("name", null);
	%>
	<%
		Person p = new Person();
		p.setAge(12);
		request.setAttribute("person", p);
	%>
	${person.age }

	<%--${person.username } --%>
	<%
		Person person = new Person();
		Add add = new Add();
		person.setAdd(add);
		request.setAttribute("person", person);
	%>
	${ person.add.name}



	<%
		Person p1 = new Person();
		p1.setName("aa111");

		Person p2 = new Person();
		p2.setName("bb");

		List list = new ArrayList();
		list.add(p1);
		list.add(p2);
		request.setAttribute("list", list);
	%>

	${list[0].name }


	<%
		Map map = new HashMap();
		map.put("a", "aaaaxxxx");
		map.put("b", "bbbb");
		map.put("c", "cccc");
		map.put("1", "1111111");
		request.setAttribute("map", map);
	%>

	${map["1"] }
	<a href="${pageContext.request.contextPath }/1.jsp">点点</a>
	${pageContext.request.contextPath }
</body>
</html>

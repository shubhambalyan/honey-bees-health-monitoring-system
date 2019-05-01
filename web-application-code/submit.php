<!DOCTYPE html>
<html> 
<head>
    <title>Smart Farm and Agriculture</title>
<style type="text/css">
body {
    border-top-style: solid;
    border-top-color: red;
    border-top-width: 5px;
    margin-top: 0px;
    margin-left: 0px;
    margin-right: 0px;
}
#one {
    float: right;
    margin-top: 20px;
    margin-right: 16px;
}
#two {
    margin-top: 8px;
    margin-left: 300px;
}
#three {
    border-bottom-width: 5px;
    border-bottom-color: red;
    border-bottom-style: solid;
}
#five {
    text-align: center;
    background-color: gray;
}

</style>
</head>
<body>
    <?php
if(!isset( $_POST['phpro_username']))
{
    //header("Location: login.php?q=1");
    $message = 'Please enter a valid username and password';
}
else 
{
    $servername= 'localhost';
    $username = 'root';
    $password = 'shubham';
    $dbname = 'honeybee';
    $conn = new mysqli($servername, $username, $password, $dbname);
    if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
     }
    $uname=$_POST["phpro_username"];
    $pass=$_POST["phpro_password"];
    //echo $uname;
    //echo $pass;
    $sql = "SELECT password from login where username='$uname'";
    $result=$conn->query($sql);
    $row=$result->fetch_assoc();
    if($row["password"]==$pass)
        echo "You're Now Logged In !! Hello Admin !!!";
    else {
        //echo "Login Failed!! Invalid Credentials!!";
        header("Location: login.php?q=1"); 
    }

}
?>
    <div>
        <header id="three">
        <img src="images/title.jpg" width="700px" height="100px" id="two">
        </header>
    </div>
    
    <div>
        <img src="images/beess.jpg" width="1365" height="400" alt="Home" usemap="#new">
        <map name="new">
            <!--area shape="poly" coords="167,72,343,71,346,241,168,243" alt="Image" href="image.php">
            <area shape="poly" coords="568,71,747,71,745,240,564,242" alt="Fragment" href="fragment.php">
            <area shape="poly" coords="968,72,1145,72,1145,244,969,240" alt="Logout" href="main.php"-->

            <area  shape="poly" coords="74,130,276,129,276,218,79,213" alt="temp" href="temp.html"/>
            <area shape="poly" coords="395,126,594,126,597,216,398,211" alt="hum" href="hum.html" />
            <area shape="poly" coords="714,124,913,125,913,214,719,213" alt="weight" href="weight.html" />
            <area shape="poly" coords="1045,125,1241,127,1247,213,1050,211" alt="gas" href="gas.html" />
            <area shape="poly" coords="1189,5,1192,64,1314,65,1314,4" alt="logout" href="main.html"  />
        </map>
    </div>
    <div>
        <footer id="four">
            <h5 id="five">&copy;2015&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SMART FARM AND AGRICULTURE</h5>
        </footer>
    </div>
</body>
</html>
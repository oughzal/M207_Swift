<?php
$email ="omar@@@oughzal.com";
if(filter_var($email,FILTER_VALIDATE_EMAIL)==true){
    echo "email valide";
}else{
    echo "email non valide";
}

?>
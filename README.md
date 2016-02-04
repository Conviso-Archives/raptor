![Alt text](https://github.com/CoolerVoid/raptor_waf/blob/master/doc/images/raptor2.png)
# raptor_waf

Raptor is a Web application firewall made in C, uses DFA(deterministic finite automaton ) to block SQL injection, Cross site scripting and path traversal.

#THis is PoC version
![Alt text](https://github.com/CoolerVoid/raptor_waf/blob/master/doc/images/help.png)

#to run:
$ git clone https://github.com/CoolerVoid/raptor_waf

$ cd raptor_waf; make; bin/raptor

#Example

Up some HTTPd server at port 80 

$ bin/Raptor -h localhost -p 80 -r 8883 -w 4 -o loglog.txt

Copy vulnerable PHP code to your web server directory

$ cp doc/test_dfa/test.php /var/www/html

Now you can test xss attacks at http://localhost:8883/test.php


# Look the docs

https://github.com/CoolerVoid/raptor_waf/blob/master/doc/raptor.pdf

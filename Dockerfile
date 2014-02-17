# A version of Ubuntu Saucy with the optional repositories enabled.
from angelrr7702/ubuntu-13.10

# This script contains the build logic.
run sudo apt-get install -y wget bash 
run wget --no-check-certificate https://raw.github.com/emchristiansen/opencv-thrift/master/continuousIntegration.sh

# The default Docker shell isn't Bash, but the build script is, so
# we need to repeatedly invoke Bash.
run bash -c "source continuousIntegration.sh; configureSystem"
run bash -c "source continuousIntegration.sh; installThrift"
run bash -c "source continuousIntegration.sh; installOpenCV"

run bash -c "source continuousIntegration.sh; installOpenCVThrift"


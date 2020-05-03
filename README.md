# Installation

Install miniconda:
    
```
cd /tmp
wget https://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh
bash Miniconda3-latest-Linux-x86_64.sh  
export PATH="$HOME/miniconda3/bin:$PATH"
```

Install the ros environment:

```
. $HOME/miniconda3/etc/profile.d/conda.sh

yes | conda create --name cheetah --channel conda-forge \
   ros-core \
   ros-actionlib \
   ros-dynamic-reconfigure \
   xeus-cling \
   xplot \
   widgetsnbextension \
   "bqplot>=0.11.4,<0.12" \
   python=3.6 
   
conda activate cheetah

yes | pip install jupyter
```
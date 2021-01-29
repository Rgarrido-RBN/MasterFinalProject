# Coral TPU installation guide for RPI4 running Ubuntu Mate 20.04

## Sofware requierements.

In order to run Coral TPU USB Acellerator on Raspberry with Ubuntu we have to consider some requirements. 

First of all, we have to set up an enviroment using Conda for manage the different packages we are going to use. So the fisrt step goes through install Anaconda.

The first step is knowing thar architecture of our device, we could check it with `uname -m` command on the terminal window. The result of this operating must be aarch64 on our RPI4.

Since we are using RPI4 one of the best choices is using **Archiconda3** which have support for aarch64 architectures. We could find more information here: https://github.com/yqlbu/archiconda3

## Setting Up our enviroment and installing requirements.

Once we have conda working fine we hve to create an eviroment and activate it. We could make this with `conda create --name tflite1-env` after that activate it with `conda activate tflite1-env`.

At this point we are working in a conda enviroment, so we are able to install our requirement packages. We could make this running the requirement file located in the repository we allready clone. We run this with `bash get_pi_requirements.sh`

### Posible issues running get_pi_requirements.sh

Depending the version of OS you use on your RPI you may have some issues. I got some issues with the version of OpenCV, so I replaced the 11th with `pip3 install opencv-python`. Make sure you have **pip3** allready installed (also **pip** could work).

If you are running Ubuntu instead of Raspbian I'm quite sure you have to replace **line 22 and 26** with ` pip3 install --extra-index-url https://google-coral.github.io/py-repo/ tflite_runtime`.

**At this point you should be able to run the requirements file in your RPI command window.**

## Getting TfLite MobilenetV1 SSD from Google.

We have to run two comands:

First:
`wget https://storage.googleapis.com/download.tensorflow.org/models/tflite/coco_ssd_mobilenet_v1_1.0_quant_2018_06_29.zip`

After make:
`unzip coco_ssd_mobilenet_v1_1.0_quant_2018_06_29.zip -d Sample_TFLite_model`

At this point you can run the video example downloaded without using Coral TPU with this command: `python3 TFLite_detection_video.py --modeldir=Sample_TFLite_model`.




# gh-code-finder

This is a simple project I came up with that will allow us to get locally an entire copy of any file from any GitHub repository!

I wanted to make this script completely in C++ language because maybe in the future I might decide to add a graphical user interface.

To use my script all you have to do is choose a username, a repository and finally the file you want to download, in particular we have:

```Bash
./gh-code-finder.app <username> <repository> <filename>
```

For example if I need the code that I used in the sensor in my [clap-detection](https://github.com/AntonioBerna/arduino-projects/tree/master/clap-detection) project then I will use the following command:

```Bash
./gh-code-finder.app AntonioBerna arduino-projects clap-detection/sensor.h
```

In which will generate the ```founds``` directory which will contain the file ```sensor.h``` !

# Todo

- [ ] Add a GUI with the ability to see the repositories and various files without remembering everything by heart!



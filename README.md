
- windows settings

1) copy files from Data\Packages\User 
2) view->groups->new groups (for inputf & outputf)
3) preferences->color scheme->monokai
   preferences->theme->adaptive

  
- mac settings 
  CPP_RUN file location on mac
/Users/{Username}/Library/Application Support/Sublime Text 3/Packages/User

gcc error (File Not Found Error while including bits/stdc++.h)

```sh
brew install gcc
cd /Library/Developer/CommandLineTools/usr/bin
cd ../include

create bits directory in there. use sudo if permission issues
sudo mkdir bits

cd bits
sudo cp ~/Downloads/stdc++.h stdc++.h
```

gcc error (fatal error: 'cstdalign' file not found)
```sh
comment out
```

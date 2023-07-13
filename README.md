## IL2CPPToWinRTBridge
这个是原始的IL2CPP(Unity)与WinRT(UWP)的通讯桥  
- 初始化及接收消息
  - Unity中你需要新建一个类继承`IIL2CPPBridge`,并实现其接口`Connect`,该接口在Unity中负责接收消息  
    并且初始化
    ```
    // Unity通讯桥初始化
    var bridge = new IL2CPPBridge();// 用你子类
    BridgeBootstrapper.SetIL2CPPBridge(bridge);
    ```
  - UWP中你需要新建一个类继承`IWinRTBridge`,并实现其接口`Connect`,该接口在UWP中负责接收消息  
    并且初始化
    ```
    // UWP通讯桥初始化
    var bridge = new WinRTBridge();// 用你子类
    BridgeBootstrapper.SetWinRTBridge(bridge);
    ```
  - 只有初始化后才会接收到消息
- 发送消息
  - Unity
    ```
    // Unity 发送消息
    public static bool Send(string message)
    {
        IWinRTBridge bridge = BridgeBootstrapper.GetWinRTBridge();
        // 如果同一时间在WinRT中IWinRTBridge已经实例化(即上文的初始化),则不为null
        if(bridge != null)
        {
            bridge.Connect(message);
            return true;
        }
        return false;
    }
    ```
    - UWP
    ```
    // UWP 发送消息
    public static bool Send(string message)
    {
        IIL2CPPBridge bridge = BridgeBootstrapper.GetIL2CPPBridge();
        // 如果同一时间在Unity中IIL2CPPBridge已经实例化(即上文的初始化),则不为null
        if(bridge != null)
        {
            bridge.Connect(message);
            return true;
        }
        return false;
    }
    ```
## InkBallBridge
这是[InkBall](https://github.com/MicaGames)项目的专用通讯桥  

具体之间看源码的注释,写的很清楚  

与原始项目的改动如下:
- 命名空间`IL2CPPToWinRTBridge`->统一`InkBallBridge`
- 通讯信息类型`string`->`BridgeMessage`

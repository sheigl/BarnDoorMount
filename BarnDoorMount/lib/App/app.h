class App
{
private:
public:
    App() = default;
    ~App() = default;
    virtual void setup() = 0;
    virtual void loop() = 0;
};
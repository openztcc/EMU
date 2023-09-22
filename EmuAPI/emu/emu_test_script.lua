function emu_run()
    local zs = ZooState()
    io.write(zs:GetZooBudget() + "Hello world from inside Lua running inside EMU running inside Zoo Tycoon!")
end
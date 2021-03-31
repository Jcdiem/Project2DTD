function init()
-- You **MUST** declare what inputs you want to use at some point
    self:addBinding("C4")
    self:addBinding("D4")
    self:addBinding("E4")
    self:addBinding("F4")
    self:addBinding("G4")
    self:addBinding("A4")
    self:addBinding("B4")

    if self.x == 0 then
        key = "C4"
    elseif self.x == 183 then
        key = "D4"
    elseif self.x == 366 then
        key = "E4"
    elseif self.x == 549 then
        key = "F4"
    elseif self.x == 732 then
        key = "G4"
    elseif self.x == 915 then
        key = "A4"
    elseif self.x == 1098 then
        key = "B4"
    end

    if(not sound_manager.playingMUS) then
        sound_manager.playMUS("FTTV")
    end

    self:refreshBindings()
end

function main()
    if self:isPressed(key) then
        self:playAnim(1, -1)
        sfx = sound_manager.playSFX(key)
    else
        self:playAnim(0, -1)
        if not (sfx == nil) then
            sound_manager.haltSFX(sfx)
        end
    end
end
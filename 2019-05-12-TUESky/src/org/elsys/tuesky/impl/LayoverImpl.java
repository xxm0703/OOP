package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.trips.Layover;

import java.time.Duration;

public class LayoverImpl implements Layover {

    private Duration duration;

    LayoverImpl(Duration duration) {
        assert(duration != null);

        this.duration = duration;
    }

    @Override
    public Duration getDuration() {
        return duration;
    }
}

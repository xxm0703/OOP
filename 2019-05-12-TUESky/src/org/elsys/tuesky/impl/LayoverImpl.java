package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.trips.Layover;

import java.time.Duration;

public final class LayoverImpl implements Layover {

    private final Duration duration;

    LayoverImpl(Duration duration) {
        assert(duration != null);

        this.duration = duration;
    }

    @Override
    public Duration getDuration() {
        return duration;
    }
}

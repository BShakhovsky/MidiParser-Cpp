# pragma once

class MidiParser_Facade
{
	// http://www.cs.cmu.edu/~music/cmsip/readings/Standard-MIDI-file-format-updated.pdf
	// http://www.nyu.edu/classes/bello/FMT_files/9_MIDI_code.pdf

	typedef std::vector<std::vector<unsigned>> Times_;
	typedef std::vector<std::vector<int16_t>> Notes_;
	Times_ times_;
	Notes_ notes_;

	MidiParser_Facade() = delete;
public:
	explicit MidiParser_Facade(const char* fileName);	// may throw std::runtime_error \
														// This module must be called just once, \
														// therefore everything is done in constructor
	const Times_& GetMilliSeconds() const
	{
		return times_;
	}
	const Notes_& GetNotes() const
	{
		return notes_;
	}
private:
	MidiParser_Facade(const MidiParser_Facade&) = delete;
	MidiParser_Facade(const MidiParser_Facade&&) = delete;
	MidiParser_Facade& operator=(const MidiParser_Facade&) = delete;
	MidiParser_Facade&& operator=(const MidiParser_Facade&&) = delete;
};